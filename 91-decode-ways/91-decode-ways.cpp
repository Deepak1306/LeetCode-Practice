class Solution {
public:    
    int numDecodings(string s) {
        int n=s.length();
        
        int dp[n+1];
        dp[0]=1;
        
        if(s[0]=='0'){
            return 0;
        }
        dp[1]=1;
        
        for(int i=2;i<=n;i++){
            
            dp[i]=0;
            
            int a=s[i-1]-'0';
            int b=s[i-2]-'0';
            
            b=b*10+a;
            
            if(a!=0){
               dp[i]+=dp[i-1]==0?0:dp[i-1];    
            }
            
            if(b>=10 && b<=26){
                dp[i]+=dp[i-2]==0?0:dp[i-2];
            }
            
            
        }
        
        return dp[n];
        
    }
};