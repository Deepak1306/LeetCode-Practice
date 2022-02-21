class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        
        bool dp[n][n];
        string str;
        
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;j++,i++){
                if(g==0){
                    if(str.length()<j-i+1){
                        str=s.substr(i,j-i+1);
                    }
                    dp[i][j]=true;
                
                
                }else if(g==1){
                    if(s[i]==s[j]){
                        if(str.length()<j-i+1){
                        str=s.substr(i,j-i+1);
                        }
                        dp[i][j]=true;
                    }else{
                        dp[i][j]=false;
                    }   
                }
                else{
                    if(s[i]==s[j]){
                        if(dp[i+1][j-1]==true && str.length()<j-i+1){
                            str=s.substr(i,j-i+1);
                        }
                        
                        dp[i][j]=true&&dp[i+1][j-1];
                    }else{
                        dp[i][j]=false;
                    }
                }
            }
        }
    
        
       return str; 
        
        
    }
};