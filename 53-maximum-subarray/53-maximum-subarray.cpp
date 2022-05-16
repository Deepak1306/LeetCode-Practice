class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     int ans=INT_MIN;
        
        int currSum=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]+currSum<nums[i]){
                currSum=nums[i];
            }else{
                currSum+=nums[i];
            }
            
            ans=max(ans,currSum);
        }
        
        return ans;
    }
};