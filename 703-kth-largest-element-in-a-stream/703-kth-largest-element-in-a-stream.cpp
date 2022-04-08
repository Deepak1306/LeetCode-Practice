class KthLargest {
public:
    
    priority_queue<int,vector<int>,greater<int>>p;
    int kth;
    
    KthLargest(int k, vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(i<k){
                p.push(nums[i]);
            }else{
                if(p.top()<nums[i]){
                    p.pop();
                    p.push(nums[i]);
                }
                
            }
        }
        kth=k;
    }
    
    int add(int val) {
        if(p.empty() || p.size()<kth){
            p.push(val);
        }else if(p.size()==kth && p.top()<val){
            p.pop();
            p.push(val);
        }
        
        return p.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */