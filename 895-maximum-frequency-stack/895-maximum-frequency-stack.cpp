class FreqStack {
public:
    
   
    unordered_map<int,int>map;
    int maxFreq;
    unordered_map<int,stack<int>>arr;
    
   
    
    void push(int val) {
      map[val]++;
        
        if(map[val]>maxFreq){
            maxFreq=map[val];
        }
        
        arr[map[val]].push(val);
    }
    
    int pop() {
        
        int ans=arr[maxFreq].top();
        arr[maxFreq].pop();
        
        map[ans]--;
        
        if(arr[maxFreq].size()==0){
            maxFreq--;
        }
        
        return ans;
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */