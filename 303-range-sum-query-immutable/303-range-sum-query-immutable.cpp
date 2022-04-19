class NumArray {
public:
    vector<int>arr={0};
    
    NumArray(vector<int>& nums) {
        int n=nums.size();
        
        arr[0]=nums[0];
        for(int i=1;i<n;i++){
            arr.push_back(arr[i-1]+nums[i]);
        }    
    }
    
    int sumRange(int left, int right) {
        if(left==0){
            return arr[right];
        }
        return arr[right]-arr[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */