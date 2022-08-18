class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n=nums.size();
        //vector<int>arr(n);
        for(int i=0;i<n;i++){
            if(nums[abs(nums[i])]<0)return abs(nums[i]);
            nums[abs(nums[i])]*=-1;
        }
        return -1;
        
    }
};