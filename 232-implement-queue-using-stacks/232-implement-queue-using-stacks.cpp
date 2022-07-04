class MyQueue {
stack<int>s;
stack<int>st;
    public:
    
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s.empty()){
            st.push(s.top());
            s.pop();
        }
        s.push(x);
        while(!st.empty()){
            s.push(st.top());
            st.pop();
        }
        
    }
    
    int pop() {
        int n=s.top();
        s.pop();
        return n;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
      if(s.empty()){
          return true;
      }  
        
        return false;
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