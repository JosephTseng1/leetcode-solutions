class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> stackA;
    queue<int> stackB;
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        stackA.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int n = stackA.size();
        for (int i = 0; i < n - 1; i++) {
            int num = stackA.front();
            stackA.pop();
            stackB.push(num);
        }
        int result = stackA.front();
        stackA.pop();
        while (!stackB.empty()) {
            int num = stackB.front();
            stackB.pop();
            stackA.push(num);
        }
        return result;
    }
    
    /** Get the top element. */
    int top() {
        int n = stackA.size();
        for (int i = 0; i < n - 1; i++) {
            int num = stackA.front();
            stackA.pop();
            stackB.push(num);
        }
        int result = stackA.front();
        stackA.pop();
        stackB.push(result);
        while (!stackB.empty()) {
            int num = stackB.front();
            stackB.pop();
            stackA.push(num);
        }
        return result;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return stackA.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
