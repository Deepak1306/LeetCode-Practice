class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        
        int dp[n];
        int ans=1;
        
        dp[0]=1;
        for(int i=1;i<n;i++){
            dp[i]=1;
            for(int j=i-1;j>=0;j--){
                if(nums[j]>=nums[i]){
                    continue;
                }
                    dp[i]=max(dp[i],dp[j]+1);
            }
            
            ans=max(ans,dp[i]);
        }
        
        return ans;
        
    }
};