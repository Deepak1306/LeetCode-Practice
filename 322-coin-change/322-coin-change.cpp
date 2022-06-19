class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int k=amount;
        
        long long dp[n+1][k+1];
        
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        
        for(int j=1;j<=k;j++){
            dp[0][j]=INT_MAX;
        }
        
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                
                if(coins[i-1]<=j){
                    dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
                }else{
                    dp[i][j]=dp[i-1][j];
                }
                
            }
        }
        
        if(dp[n][k]>=INT_MAX){
            return -1;
        }
        
        return dp[n][k];
        
        
        
    }
};