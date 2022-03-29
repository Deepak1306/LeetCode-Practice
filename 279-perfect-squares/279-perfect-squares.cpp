class Solution {
public:
    int numSquares(int n) {
        
        int dp[n+1];
        if(n<=3){
            return n;
        }
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        dp[3]=3;
        
        for(int i=4;i<=n;i++){
            dp[i]=INT_MAX;
            
            for(int j=1;j<n;j++){
                int x=j*j;
                if(x>i){
                    break;
                }else{
                    dp[i]=min(dp[i],1+dp[i-x]);
                }
            }
        }
        
        return dp[n];
    }
};