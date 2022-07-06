class MinStack {
public:
    stack<long long int> s;
    long long int mnum;
    
    MinStack() {
        
    }
    
    void push(int val) {
       if(s.empty()) mnum=val;
      
        if(val>=mnum)  s.push(val);
        else{
            s.push(1ll*2*val-mnum);
            mnum=val;
        }
    }
    
    void pop() {
       if(s.top()<mnum){
           mnum=2*mnum-s.top();
       }
        s.pop();
    }
    
    int top() {
        if(s.top()<mnum) return mnum;
        else return s.top();
    }
    
    int getMin() {
        return mnum;
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