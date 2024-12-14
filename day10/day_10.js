/**
 * https://leetcode.com/problems/valid-palindrome/
 * approach1: filter non alphanumeric chars and use two pointers.
 * time complexity: O(n)
 * space: O(n)
 */


/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    let str = "";
    for(const ch of s){
        if(ch >= 'A' && ch <= 'Z'){
            str += ch.toLowerCase();
        }
        else if((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z')){
            str += ch
        }
    }
    console.log(str)
    let left = 0, right = str.length - 1;

    while(left < right){
        const lChar = str[left];
        const rChar = str[right];
        if(lChar != rChar) return false;
        left++;
        right--;
    }
    return true;
};