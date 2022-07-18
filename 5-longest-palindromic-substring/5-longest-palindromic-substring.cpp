class Solution {
public:
    string longestPalindrome(string s) {
        
        int n=s.length();
        
        bool dp[n][n];
        
        string ans="";
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                if(g==0){
                    dp[i][j]=true;
                    
                    if(ans.length()<j-i+1){
                        ans=s.substr(i,j-i+1);
                    }
                }else if(g==1){
                    if(s[i]==s[j]){
                        dp[i][j]=true;
                        
                        if(ans.length()<j-i+1){
                            ans=s.substr(i,j-i+1);
                        }
                    }else{
                        dp[i][j]=false;
                    }
                    
                    
                    
                }else{
                    if(s[i]==s[j]){
                        dp[i][j]=dp[i+1][j-1];
                        
                        if(dp[i][j]==true){
                            if(ans.length()<j-i+1){
                            ans=s.substr(i,j-i+1);
                           }     
                        }
                       
                    }else{
                        dp[i][j]=false;
                    }
                }
            }
        }
        return ans;
        
    }
};