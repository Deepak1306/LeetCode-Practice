class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if(n==0 || n==1){
            return 0;
        }
        
        int dp[k+1][n];
        
        for(int i=0;i<=k;i++){
            int m=INT_MIN;
            for(int j=0;j<n;j++){
                if(i==0){
                    dp[i][j]=0;
                }else if(j==0){
                    dp[i][j]=0;
                }else{
                    
                    dp[i][j]=dp[i][j-1];
                    m=max(m,dp[i-1][j-1]-prices[j-1]);
                    
                    dp[i][j]=max(dp[i][j],m+prices[j]);
                    
                }
            }
        }
        
        return dp[k][n-1];
        
    }
};