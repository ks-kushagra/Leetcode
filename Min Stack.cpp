Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

Methods pop, top and getMin operations will always be called on non-empty stacks.
_____________________________________________________________________________________________________________________________________________________________________________________________________________________________________---

class MinStack {
public:
    /** initialize your data structure here. */
    stack <int> s;
    stack <int> ss;
    MinStack() {
        
        s= stack<int> ();
        ss= stack<int> ();
    }
    
    void push(int x) {
        s.push(x);
        if(ss.empty())
            ss.push(x);
        
        else if(ss.top()>=x)
            ss.push(x);
    }
    
    void pop() {
        
        if(s.empty())
            return ;
        int t = s.top();
        s.pop();
        
        if(ss.empty())
            return ;
        else if(ss.top() == t)
            ss.pop();
        
    }
    
    int top() {
        if(s.empty())
            return -1;
        
        return s.top();
    }
    
    int getMin() {
        if(ss.size()>0)
            return ss.top();
        
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
