// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
int dp[1001][1001];
class Solution{
    public:
    long long solve(int arr[],int i, int j){
        if(i>j){
            return 0;
        }
        
        if(i==j){
            return arr[i];
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        long long a=0;
        long long b=0;
        
        a=arr[i]+min(solve(arr,i+2,j),solve(arr,i+1,j-1));
        b=arr[j]+min(solve(arr,i,j-2),solve(arr,i+1,j-1));
        
        
        
        return dp[i][j]=max(a,b);
        
        
        
    }
    long long maximumAmount(int arr[], int n){
        // Your code here
        memset(dp,-1,sizeof(dp));
        return solve(arr,0,n-1);
    }
};

// { Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends