/**
 * https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
 * 
 * 150. Evaluate Reverse Polish Notation
 * 
 * approach1: stack, its a postfix notation, so every operator operates on last 2 operands.
 * time: O(n)
 * space: O(n)
*/

class Solution {
public:
    bool isAnOperator(string &s){
        return s == "+" or s == "-" or s == "*" or s == "/";
    }

    int calculateResult(int firstOperand, int secondOperand, string &op){
        if(op == "+") return firstOperand + secondOperand;
        if(op == "-") return firstOperand - secondOperand;
        if(op == "*") return firstOperand * secondOperand;
        if(op == "/") return firstOperand / secondOperand;
        return 0;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(string &s: tokens){
            if(isAnOperator(s)){
                if(st.size() >= 2){
                    int secondOperand = st.top();
                    st.pop();
                    int firstOperand = st.top();
                    st.pop();
                    int res = calculateResult(firstOperand, secondOperand, s);
                    st.push(res);
                }
            }else{
                int number = stoi(s);
                st.push(number);
            }
        }
        return st.top();
    }
};


/**
 * appoach2: Recursion
 * time: O(n)
 * space: O(n) -> recursion stack.
*/

class Solution {
public:
    bool isAnOperator(string& s) {
        return s == "+" or s == "-" or s == "*" or s == "/";
    }

    int evalRPN(vector<string>& tokens) {
        int n = tokens.size() - 1;
        return solve(tokens, n);
    }

    int solve(vector<string>& tokens, int &idx) { 
        if(isAnOperator(tokens[idx])){
            string op = tokens[idx];
            int op1 = solve(tokens, --idx), op2 = solve(tokens, --idx);
            if(op == "+") return op1 + op2;
            if(op == "-") return op2 - op1;
            if(op == "*") return op1 * op2;
            if(op == "/") return op2 / op1;
        }
        return stoi(tokens[idx]);
    }
};