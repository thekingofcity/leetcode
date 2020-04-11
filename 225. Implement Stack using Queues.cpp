class MyStack {
private:
    queue<int> base;
    queue<int> alter;
public:
    /** Initialize your data structure here. */
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        base.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while(base.size()>1){
            alter.push(base.front());
            base.pop();
        }
        int ret=base.front();
        base.pop();
        swap(base, alter);
        return ret;
    }
    
    /** Get the top element. */
    int top() {
        while(base.size()>1){
            alter.push(base.front());
            base.pop();
        }
        int ret=base.front();
        alter.push(base.front());
        base.pop();
        swap(base, alter);
        return ret;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return base.size()==0;
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