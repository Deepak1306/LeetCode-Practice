// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}// } Driver Code Ends


int minDeletions(string A, int n) { 
    //complete the function here 

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

    return n-dp[n][n];
    
} 