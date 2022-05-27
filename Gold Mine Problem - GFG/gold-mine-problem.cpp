// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
   
   


    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        
          int dp[n][m];
          int mod=1e9+7;
          
          if(n<=1){
             int ans=0;
             for(int i=0;i<m;i++){
                 ans+=M[0][i];
             }
             
             return ans;
          }
          
          for(int j=m-1;j>=0;j--){
              for(int i=0;i<n;i++){
                  if(j==m-1){
                      dp[i][j]=M[i][j];
                  }else if(i==n-1){
                      dp[i][j]=(M[i][j]+max(dp[i-1][j+1],dp[i][j+1]))%mod;
                  }else if(i==0){
                      dp[i][j]=(M[i][j]+max(dp[i][j+1],dp[i+1][j+1]))%mod;
                  }
                  else{
                      dp[i][j]=(M[i][j]+max(dp[i-1][j+1],max(dp[i][j+1],dp[i+1][j+1])))%mod;
                  }
              }
          }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max(ans,dp[i][0]);
        }
        
        
        return ans%mod;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends