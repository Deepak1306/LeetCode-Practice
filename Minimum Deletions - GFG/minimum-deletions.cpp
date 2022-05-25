// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int minimumNumberOfDeletions(string A) { 
        // code here
        int n=A.length();

    int dp[n+1][n+1];
    string B=A;
    reverse(B.begin(),B.end());
    
    for(int i=0;i<=n;i++){
      dp[i][0]=0;
    }

    for(int j=1;j<=n;j++){
      dp[0][j]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(A[i-1]==B[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }

return    n- dp[n][n];
    } 
};

// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}  // } Driver Code Ends