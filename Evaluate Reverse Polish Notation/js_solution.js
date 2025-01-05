/**
 * @param {string[]} tokens
 * @return {number}
 * approach 1: using stack
 * time: O(n)
 * space: O(n)
 */

var isAnOperator = function (op) {
  return op == "+" || op == "-" || op == "*" || op == "/";
};

var evalRPN = function (tokens) {
  const stack = [];

  for (const t of tokens) {
    if (isAnOperator(t)) {
      const op2 = stack.pop();
      const op1 = stack.pop();
      var res;
      switch (t) {
        case "+":
          res = op1 + op2;
          break;
        case "-":
          res = op1 - op2;
          break;
        case "*":
          res = op1 * op2;
          break;
        case "/":
          res = Math.trunc(op1 / op2);
      }
      stack.push(Math.floor(res));
    } else {
      const num = Number(t);
      stack.push(num);
    }
  }
  return stack.pop();
};

/**
 * Recursion
 * time: O(n)
 * space: O(n)
 */

/**
 * @param {string[]} tokens
 * @return {number}
 */

var isAnOperator = function (op) {
  return op == "+" || op == "-" || op == "*" || op == "/";
};

var evalRPN = function (tokens) {
  const n = tokens.length - 1;
  return solve(tokens, { idx: n });
};

var solve = function (tokens, ref) {
  const idx = ref.idx;
  if (isAnOperator(tokens[idx])) {
    let op = tokens[idx];
    ref.idx--;
    const op1 = solve(tokens, ref);
    ref.idx--;
    const op2 = solve(tokens, ref);
    if (op == "+") {
      return op1 + op2;
    }
    if (op == "-") {
      return op2 - op1;
    }
    if (op == "*") {
      return op2 * op1;
    }
    if (op == "/") {
      return Math.trunc(op2 / op1);
    }
  }
  return Number(tokens[idx]);
};

/**
 * primitive types are always passed by value, so we need to convert it to obj to pass by reference.
 */
