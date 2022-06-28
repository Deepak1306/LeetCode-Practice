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
        
        long long dp[3][n+1];
        int mod=1e9+7;
        if(n==1){
            return k;
        }
        
        dp[0][1]=0;
        dp[1][1]=k;
        dp[2][1]=k;
        
        for(int i=2;i<=n;i++){
            for(int j=0;j<3;j++){
            
            if(j==0){
             dp[j][i]=dp[j+1][i-1]%mod;   
            }else if(j==1){
             dp[j][i]=((k-1)*dp[j+1][i-1])%mod;
            }else{
             dp[j][i]=(dp[j-1][i]+dp[j-2][i])%mod;    
            }
                
            }
            
        }
        
        return dp[2][n];
        
        
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