/**
 * approach1: filter and then compare using two pointers
 * time complexity: O(n)
 * space: O(n)
*/

class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for(int i=0; i<s.length(); i++){
            if(s[i] >= 'A' and s[i] <= 'Z'){
                char ch = (char) tolower(s[i]);
                str.push_back(ch);
            }else if((s[i] >= 'a' and s[i] <= 'z') or (s[i] >= '0' and s[i] <= '9')){
                str.push_back(s[i]);
            }
        }

        int left = 0, right = str.length() -1;

        while(left < right){
            if(str[left] != str[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};

/**
 * approach2: filter and compare in run time + two pointer
 * isalnum(char) checks whether the provided character is alphanumeric
 * time complexity: O(n)
 * space: O(1)
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;

        while (left < right){
            if(!isalnum(s[left])){
                left++;
                continue;
            }
            if(!isalnum(s[right])){
                right--;
                continue;
            }
            if(tolower(s[left]) != tolower(s[right])) return false;
            left++;
            right--;
        }
        return true;
    }
};