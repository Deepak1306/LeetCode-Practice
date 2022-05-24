class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        
        
        int m=(target+sum)/2;
        
        if(target>sum || target+sum <0 || (target+sum)%2!=0 ){
            return 0;
        }
        
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        
        for(int j=1;j<=m;j++){
            dp[0][j]=0;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        return dp[n][m];
    }
};