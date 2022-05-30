// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    long long int  countPS(string A)
    {
       //Your code here
        long long int n=A.length();
        
        long long int dp[n][n];
        
        long long int mod=1e9+7;
        
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;j++,i++){
                if(g==0){
                   dp[i][j]=1; 
                }else if(g==1){
                    
                    if(A[i]==A[j]){
                        dp[i][j]=3;
                    }else{
                        dp[i][j]=2;
                    }
                  
                }else{
                  if(A[i]==A[j]){
                      dp[i][j]=(dp[i][j-1]+dp[i+1][j]+1)%mod;
                  }else{
                      dp[i][j]=(dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1])%mod;
                  }
                  
                  if(dp[i][j]<0){
                      dp[i][j]+=mod;
                  }
                }
            }
        }
        
        return dp[0][n-1]%mod;
      
        
    }
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends