class MinStack {
private:
    stack<int> s;
    stack<int> ms;
    int m;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        s.push(x);
        if(s.size()==1) m=x;
        else m=min(m, x);
        ms.push(m);
    }
    
    void pop() {
        s.pop();
        if(m==ms.top()){
            ms.pop();
            if(ms.size()>0) m=ms.top();
        }else{
            ms.pop();
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return ms.top();
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