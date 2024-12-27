/**
 * https://leetcode.com/problems/longest-repeating-character-replacement/description/
 * approach: check all substrings possible.
 * time: O(n^2)
 * space: O(n)
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n= s.length(), ans= 0;

        for(int i=0; i<n; i++){
            string cur_substr = "";
            unordered_map<char, int>mp;
            char primary = s[i];
            for(int j=i; j<n; j++){
                cur_substr.push_back(s[j]);
                mp[s[j]]++;
                if(mp[s[j]] > mp[primary]) primary = s[j];
                int substr_len = cur_substr.length();
                int replacements_cnt = substr_len - mp[primary];
                if(replacements_cnt <= k){
                    ans = max(ans, substr_len);
                }
            }
        }
        return ans;
    }
};

/**
 * approach2: sliding window
 * time: O(n)
 * space: O(n)
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, n = s.length(), maxFreq = 0, ans = 0;
        int freq[26] = {0};

        while(r < n){
            freq[s[r] - 'A']++;
            maxFreq = max(maxFreq, freq[s[r] - 'A']);
            //check if current segment is a valid one.
            while(r-l+1 - maxFreq > k){
                freq[s[l] - 'A']--;
                maxFreq = 0;
                for(int i=0; i<26; i++){
                    maxFreq = max(maxFreq, freq[i]);
                }
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};

/**
traverse the string, for every [l,r] segment, check if its valid
if not, shrink the window.
number of replacements in any substr = len - max freq of any char.

O((n+n)*26) & O(26)
*/

/**
 * approach3: optimized sliding window
 * time: O(n)
 * space: O(1)
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, n = s.length(), maxFreq = 0, ans = 0;
        int freq[26] = {0};

        while(r < n){
            freq[s[r] - 'A']++;
            maxFreq = max(maxFreq, freq[s[r] - 'A']);
            //when its invalid, now we don't run while loop and don't update maxFreq.
            //just shrink the window by 1.
            //step1: remove only 1 char in one go.  
            //step2: dont update maxFreq.
            //reason: when a new char came and substr got invalid, we remove one char from start.
            //new iteration, so as the length increases, to get a better answer, we need to have a bigger maxFreq
            //in last iteration when we removed one char, maxFreq changed but we didn't update
            //as to get a new bigger ans, length should go up and maxFreq should go up, if we aren't getting a valid substr on maxFreq 3, we won't get on 2,1,0..
            // we need 4,5,6.. and if theres one so, we'll get it in the start of iteration.
            if(r-l+1 - maxFreq > k){
                freq[s[l] - 'A']--;
                l++;
            }
            if(r-l+1 - maxFreq <= k){
                ans = max(ans, r-l+1);
            }
            r++;
        }
        return ans;
    }
};