class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
     
        vector<vector<vector<int>>>dp(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
        
        
        for(int i=1;i<=strs.size();i++){
            int a=count(strs[i-1].begin(),strs[i-1].end(),'0');
            int b=strs[i-1].size()-a;
            
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    
                    
                    if(j-a>=0 && k-b>=0){
                        dp[i][j][k]=max(1+dp[i-1][j-a][k-b],dp[i-1][j][k]);
                    }else{
                        dp[i][j][k]=dp[i-1][j][k];
                    }
                    
                }
            }
            
            
        }
        return dp[strs.size()][m][n];
        
        
    }
};