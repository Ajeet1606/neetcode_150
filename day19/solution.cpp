/** https://leetcode.com/problems/minimum-window-substring/description/

naive approach: we can generate all substrings and check if it satisfies the condition and pick the shorted one.

approach1:
time: O(n1+n2)
space: O(n)
*/

class Solution {
public:
    string minWindow(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        if (n1 < n2)
            return "";

        unordered_map<char, int> t_freq, substr_freq;
        unordered_set<char> t_chars, substr_chars;

        for (int i = 0; i < n2; i++) {
            t_freq[s2[i]]++;
            t_chars.insert(s2[i]);
        }

        int l = 0, r = 0;
        int ans_l = 0, ans_r = 0, ans_len = INT_MAX;
        while (r < n1) {
            substr_freq[s1[r]]++;
            if (t_chars.count(s1[r]) > 0 &&
                substr_freq[s1[r]] == t_freq[s1[r]]) {
                substr_chars.insert(s1[r]);
            }
            r++;

            // if we're in valid state, shrink.
            while (t_chars.size() == substr_chars.size()) {
                if (r - l < ans_len) {  //r is already at 1 step ahead.
                    ans_len = r - l;
                    ans_l = l;
                    ans_r = r-1;
                }

                if (t_chars.count(s1[l]) > 0) {
                    if (substr_freq[s1[l]] == t_freq[s1[l]]) {
                        substr_chars.erase(s1[l]);
                    }
                }
                substr_freq[s1[l]]--;
                l++;
            }
        }
        if(ans_len == INT_MAX) return "";
        return s1.substr(ans_l, ans_len);
    }
};

/*
approach2:
time: (m+n)
space: O(n)

*/
class Solution {
public:
    string minWindow(string s, string t) {
        int n1 = s.length(), n2 = t.length();
        if(n1 < n2) return "";
        unordered_map<char, int>freq;

        for(char &ch: t){
            freq[ch]++;
        }

        int st = -1, len = 1e9, chars_found_from_t = 0;
        int l = 0, r = 0;
        while(r < n1){
            if(freq[s[r]] > 0){
                chars_found_from_t++;
            }
            freq[s[r]]--;

            while(chars_found_from_t == n2 && l <= r){
                if(len > r-l+1){
                    len = r-l+1;
                    st = l;
                }
                freq[s[l]]++;
                if(freq[s[l]] > 0) chars_found_from_t--;
                l++;
            }
            r++;
        }
        if(st == -1) return "";
        return s.substr(st, len);
    }
};


