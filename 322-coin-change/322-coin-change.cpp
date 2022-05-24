class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int m=amount;
        
        int dp[n+1][m+1];
        
        for(int i=1;i<=n;i++){
            dp[i][0]=0;
        }
        
        for(int j=0;j<=m;j++){
            dp[0][j]=INT_MAX;
        }
        
        for(int j=1;j<=m;j++){
            if(j%coins[0]==0){
                dp[1][j]=(j/coins[0]);
            }else{
                dp[1][j]=INT_MAX;
            }
        }
        
        
        for(int i=2;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(coins[i-1]<=j){
                   if(dp[i][j-coins[i-1]]==INT_MAX){
                       dp[i][j]=min(dp[i-1][j],dp[i][j-coins[i-1]]);
                   }else{
                       dp[i][j]=min(dp[i-1][j],dp[i][j-coins[i-1]]+1);
                   }
                        
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        if(dp[n][m]==INT_MAX){
            return -1;
        }else{
            return dp[n][m];
        }
    }
};