// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        int dp[N][N];
        
        for(int j=N-1;j>=0;j--){
            dp[N-1][j]=Matrix[N-1][j];
        }
        
        for(int i=N-2;i>=0;i--){
            for(int j=N-1;j>=0;j--){
                if(j==0){
                    dp[i][j]=Matrix[i][j]+max(dp[i+1][j],dp[i+1][j+1]);
                }else if(j==N-1){
                    dp[i][j]=Matrix[i][j]+max(dp[i+1][j],dp[i+1][j-1]);
                }else{
                    dp[i][j]=Matrix[i][j]+max(dp[i+1][j-1],max(dp[i+1][j],dp[i+1][j+1]));
                }
            }
        }
        
        int ans=INT_MIN;
        
        for(int j=0;j<N;j++){
            ans=max(ans,dp[0][j]);
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends