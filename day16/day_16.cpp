/**
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * approach1: use unordered_set and two pointers: sliding window.
 * time complexity: O(n)
 * space complexity: O(n)
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>freq;
        int ans = 0, n = s.length();

        int left = 0, right = 0;

        while(left <= right and right < n){
            char cur = s[right];
            if(freq.count(cur) > 0){
                int sz = freq.size();
                ans = max(ans, sz);
                while(s[left] != cur and left <= right){
                    freq.erase(s[left]);
                    left++;
                }
                //reached cur
                left++; //we've to remove this as well. which get substituted with inserting cur.

            }else{
                freq.insert(cur);
            }
            right++;
        }
        int sz = freq.size();
        ans = max(ans, sz);
        return ans;
    }
};