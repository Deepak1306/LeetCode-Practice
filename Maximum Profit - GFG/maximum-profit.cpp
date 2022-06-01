// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        // code here
        
        int dp[K+1][N];
        
        
        for(int i=0;i<=K;i++){
            int m=INT_MIN;
            for(int j=0;j<N;j++){
                if(i==0){
                    dp[i][j]=0;
                }else if(j==0){
                    dp[i][j]=0;
                }else{
                    dp[i][j]=dp[i][j-1];
                    m=max(dp[i-1][j-1]-A[j-1],m);
                    dp[i][j]=max(m+A[j],dp[i][j]);
                    
                }
            }
        }
    
    return dp[K][N-1];
    }
    
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends