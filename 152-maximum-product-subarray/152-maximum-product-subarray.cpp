class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int maxSum=1;
        int minSum=1;
        
        
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                swap(maxSum,minSum);
            }
            
            maxSum=max(nums[i],maxSum*nums[i]);
            minSum=min(nums[i],minSum*nums[i]);
            
            ans=max(ans,maxSum);
        }
        
        return ans;
        
        
        
    }
};