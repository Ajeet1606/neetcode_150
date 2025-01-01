/**
 * https://leetcode.com/problems/permutation-in-string/
 * approach1: sliding window
 * time: O(nlogn + mlogm)
 * space: O(1)
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        if(n1 > n2) return false;
        sort(begin(s1), end(s1));
        
        //generate all substrings.
        int left = 0, right = n1-1;
        
        while(right < n2){
            string substr = "";
            for(int i = left; i<=right; i++) 
                substr.push_back(s2[i]);
            sort(begin(substr), end(substr));
            if(substr == s1) return true;
            right++;
            left++;
        }
        return false;
    }
};