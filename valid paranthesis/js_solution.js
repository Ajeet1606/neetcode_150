/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    const stack = [];

    for(const ch of s){
        if(ch == '(' || ch == '{' || ch == '['){
            stack.push(ch);
        }else{
            if(stack.length == 0) return false;
            const top = stack[stack.length -1];
            if((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[')){
                stack.pop();
            }else{
                return false;
            }
        }
    }
    return !stack.length;
};
/**
 * array support all stack operations.
 * time: O(n)
 * space: O(n)
 */