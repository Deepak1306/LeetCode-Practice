class Solution {
public:
    int dp[2001][2001];
    
    bool isPalindrome(string &s, int i,int j){
        
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            
            i++;
            j--;
        }
        
        return true;
    }
    
    int helper(string &s , int i ,int j){
        if(i>=j){
            dp[i][j]=0;
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(isPalindrome(s,i,j)){
            return dp[i][j]=0;
        }
        
        int ans=INT_MAX;
        
        for(int k=i;k<j;k++){
           if (isPalindrome(s,i,k)){
               ans = min(ans,1+helper(s,k+1,j));
           }
        }
        
        return dp[i][j]=ans;
        
    }
    
    
    int minCut(string s) {
      int n=s.length();
        memset(dp,-1, sizeof(dp));
        
        
        return helper(s,0,n-1);
        
        
    }
};