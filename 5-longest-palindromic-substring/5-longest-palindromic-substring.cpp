class Solution {
public:
    string longestPalindrome(string A) {
         int n=A.length();
        
        string s=A;
        reverse(s.begin(),s.end());
        
        string str="";
        
        bool dp[n][n];
        
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                
                if(g==0){
                   dp[i][j]=true;
                    
                    if(str.length()<j-i+1){
                        str=A.substr(i,j-i+1);
                    }
                    
                }else if(g==1){
                    if(A[i]==A[j]){
                        dp[i][j]=true; 
                        
                       if(str.length()<j-i+1){
                        str=A.substr(i,j-i+1);
                       }
                        
                    }else{
                        dp[i][j]=false;
                    }
                    
                }else{
                    if(A[i]==A[j]){
                        dp[i][j]=dp[i+1][j-1]; 
                        
                        
                        if(dp[i][j]==true){
                            
                          if(str.length()<j-i+1){
                              str=A.substr(i,j-i+1);
                           }   
                        }
                        
                    }else{
                        dp[i][j]=false;
                    }
                    
                }
                
                
                
            }
        }
        
        
        return str;
    }
};