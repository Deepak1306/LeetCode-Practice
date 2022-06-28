// { Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

 // } Driver Code Ends
// Complete this function
long long int count(long long int n)
{    
    int arr[3]={3,5,10};
    
	long long int dp[4][n+1];
	
	for(int j=1;j<=n;j++){
	    dp[0][j]=0;
	}
	
	for(int i=0;i<=3;i++){
	    dp[i][0]=1;
	}
	
	for(int i=1;i<=3;i++){
	    for(int j=1;j<=n;j++){
	        if(arr[i-1]<=j){
	            dp[i][j]=dp[i-1][j]+dp[i][j-arr[i-1]];
	        }else{
	            dp[i][j]=dp[i-1][j];
	        }
	    }
	}
	
	return dp[3][n];
	
}

// { Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}  // } Driver Code Ends