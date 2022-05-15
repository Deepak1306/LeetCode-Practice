class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.length();
        int n=p.length();
        
        int dp[n+1][m+1];
        
        dp[0][0]=true;
        for(int i=1;i<=n;i++){
            if(p[i-1]=='*'){
                dp[i][0]=dp[i-2][0];
            }else{
                dp[i][0]=false;
            }
            
        }
        
        for(int j=1;j<=m;j++){
            dp[0][j]=false;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                
                if(s[j-1]==p[i-1]){
                   dp[i][j]=dp[i-1][j-1]; 
                }
                else if(p[i-1]=='.'){
                    dp[i][j]=dp[i-1][j-1];
                }else if(p[i-1]=='*'){
                    dp[i][j]=dp[i-2][j];
                    
                    if(p[i-2]==s[j-1] || p[i-2]=='.'){
                        dp[i][j]=dp[i][j]||dp[i][j-1];
                           }
                }else{
                    dp[i][j]=false;
                }
                
                
            }
        }
        
        
        return dp[n][m];
    }
};