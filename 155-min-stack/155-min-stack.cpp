class MinStack {
     pair<int,int> arr[30000];
    int size=0;
    int m=INT_MAX;
    public:
    MinStack() {
        
    }
    
    void push(int val) {
        m=min(m,val);
        arr[size]={m,val};
        size++;
    }
    
    void pop() {
        if(size==0){
            return ;
        }
        size--;
        if(size==0){
            m=INT_MAX;
        }else{
        m=arr[size-1].first;
            
        }
        
    }
    
    int top() {
        if(size==0){
            return -1;
        }
        return arr[size-1].second;
    }
    
    int getMin() {
        if(size==0){
            return -1;
        }
        return arr[size-1].first;
        
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