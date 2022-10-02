class Solution {
public:
    int dp[1001][31];
    int mod=1e9+7;
    
    int solve(int n,int m,int k){ 
        if(n==0){
            if(k==0){
                return 1;
            }
            return 0;
        }else if(k==0){
            return 0;
        }
        else if(dp[k][n]!=-1){
            return dp[k][n];
        }
        int ans=0;
        for(int i=1;i<=m;i++){
            if(i<=k){
                int x=solve(n-1,m,k-i);
                ans+=x;
                ans%=mod;
            }
        }
        
        return dp[k][n]=ans%mod;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
        
        return solve(n,k,target);
    }
};