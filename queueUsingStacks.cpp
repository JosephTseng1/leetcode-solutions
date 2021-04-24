class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> one;
    stack<int> two;
    
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        one.push(x);
    }
    

    int pop() {
        while (!one.empty()) {
            int num = one.top();
            two.push(num);
            one.pop();
        }
        int result = two.top();
        two.pop();
        
        while (!two.empty()) {
            int num = two.top();
            one.push(num);
            two.pop();
        }
        return result;
    }
    
    /** Get the front element. */
    int peek() {
        while (!one.empty()) {
            int num = one.top();
            two.push(num);
            one.pop();
        }
        int num = two.top();
        while (!two.empty()) {
            int num = two.top();
            one.push(num);
            two.pop();
        }
        return num;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return (one.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
