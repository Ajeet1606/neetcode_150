/** https://leetcode.com/problems/valid-parentheses/
 * approach1: using stack: edge case: unbalanced paranthesis "[" or "]"
 * time: O(n)
 * space: O(n)
*/

class Solution {
public:
    bool isMatching(char &c1, char &c2){
        if((c1 == '(' and c2 == ')') or (c1 == '{' and c2 == '}') or (c1 == '[' and c2 == ']'))
        return true;
        return false;
    }

    bool isValid(string s) {
        stack<char>st;

        for(int i=0; i<s.length(); i++){
            if(s[i] == '(' or s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }else{
                if(st.empty()) return false;
                char top = st.top();
                if(isMatching(top, s[i])){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};

/**
 * approach2: using stack tricky approach.
 * time: O(n)
 * space: O(n)
*/

class Solution {
public:

    bool isValid(string s) {
        stack<char>st;

        for(int i=0; i<s.length(); i++){
            if(s[i] == '('){
                st.push(')');
            }else if(s[i] == '{'){
                st.push('}');
            }else if(s[i] == '['){
                st.push(']');
            }else if(st.empty()){
                return false;
            }else if(!st.empty()){
                char top = st.top();
                st.pop();
                if(s[i] != top){
                    return false;
                }
            }
        }
        return st.empty();
    }
};

/**
 * if(s.length() % 2 != 0) return false;
 * a prior odd length check can be added.
*/