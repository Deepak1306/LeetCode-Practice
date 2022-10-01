class Solution {
public:
    int dp[101];
    int solve(string s,int i){
        if(i==s.length()){
            return 1 ;
        }
        if(s[i]=='0'){
            return 0 ;
        }else if(dp[i]!=-1){
            return dp[i];
        }
        int ans=0;
       ans+= solve(s,i+1);
        
        
        if(i<s.length()-1 ){
            int a=s[i]-'0';
            int b=s[i+1]-'0';
            
            a=a*10+b;
            
            if(a>=10 && a<=26){
            ans+=solve(s,i+2);    
            }
            
        }
        return dp[i]=ans;
    }
    
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0);
        
    }
};