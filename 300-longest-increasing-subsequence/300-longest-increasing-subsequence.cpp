class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans =1;
        
        int n=nums.size();
        vector<int>dp(n,1);
        
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]<=nums[j]){
                    continue;
                }else{
                    dp[i]=max(dp[i],1+dp[j]);
                }
                
                ans=max(ans,dp[i]);
            }
        }
        
        return ans;
        
    }
};