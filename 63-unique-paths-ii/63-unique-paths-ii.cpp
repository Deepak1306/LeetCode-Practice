class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
       int m=arr.size();
       int n=arr[0].size();
        
        vector<vector<long long int>>dp(m,vector<long long int>(n,0));
        
        int mod=2*1e9;
        
        if(arr[m-1][n-1]==1){
            return 0;
        }
        dp[m-1][n-1]=1;
        
        for(int i=m-2;i>=0;i--){
            if(arr[i][n-1]==1){
                continue;
            }
            dp[i][n-1]=dp[i+1][n-1];
        }
        
        for(int j=n-2;j>=0;j--){
            if(arr[m-1][j]==1){
                continue;
            }
            dp[m-1][j]=dp[m-1][j+1];
        }
        
        
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                
                if(arr[i][j]==1){
                    continue;
                }
                dp[i][j]=(dp[i+1][j]%mod+dp[i][j+1]%mod)%mod;
            }
        }
        
        return dp[0][0]%mod;
        
    }
};