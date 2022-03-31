class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
      
        int n=nums.size();
        
    int preSum[n];
        
        preSum[0]=nums[0];
        for(int i=1;i<n;i++){
            preSum[i]=preSum[i-1]+nums[i];
        }
        
        vector<vector<int>> dp(n,vector<int>(m+1,INT_MAX));
        
        dp[0][0]=0;
        
        for(int i=0;i<n;i++){
            dp[i][1]=preSum[i];
        }
        
        for(int i=0;i<n;i++){
            for(int j=2;j<=m;j++){
                for(int k=0;k<i;k++){
                    dp[i][j]=min(dp[i][j],max(dp[k][j-1],preSum[i]-preSum[k]));
                }
            }
        }
        return dp[n-1][m];
        
        
        
    }
};