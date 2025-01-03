/**
 * https://leetcode.com/problems/min-stack/description/
 * approach1: stack + min counter.
 * time: O(1)
 * space: O(n)
*/

class MinStack {
private: 
    vector<pair<int, int>>arr;
    int mn_so_far = INT_MAX;

public:

    MinStack() {
        
    }
    
    void push(int val) {
        mn_so_far = min(mn_so_far, val);
        arr.push_back({val, mn_so_far});
    }
    
    void pop() {
        arr.pop_back();
        if(arr.size() == 0) mn_so_far = INT_MAX;
        else mn_so_far = arr.back().second;
    }
    
    int top() {
        return arr.back().first;
    }
    
    int getMin() {
        return arr.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

//two stacks can also be used, one for main other for tracking min.
//we can remove the min counter and directly use the top elements second in above soln.