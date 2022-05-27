// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long countWays(int n, int k){
        // code here
        long long dp[3][n];
        int mod=1e9+7;
        
        if(n==1){
            return k;
        }
    
         
        dp[0][1]=k;
        dp[1][1]=k*(k-1);
        dp[2][1]=dp[0][1]+dp[1][1];
        
        for(int j=2;j<n;j++){
            for(int i=0;i<3;i++){
                if(i==0){
                    dp[i][j]=dp[i+1][j-1]%mod;
                }else if(i==1){
                    dp[i][j]=(k-1)*(dp[i+1][j-1])%mod;
                }else{
                    dp[i][j]=(dp[i-1][j]+dp[i-2][j])%mod;
                }
            }
        }
        
        
        return dp[2][n-1]%mod;
        
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends