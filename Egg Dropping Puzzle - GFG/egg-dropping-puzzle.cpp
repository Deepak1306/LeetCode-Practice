// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int solve(int n, int k, int dp[201][201]){
        if(n<=1){
            return k;
        }
        
        if(k<=1){
            return k;
        }
        
        if(dp[n][k]!=-1){
            return dp[n][k];
        }
        
        int ans=INT_MAX;
        
        int i=1;
        int j=k;
        
        while(i<=j){
            int mid=i+(j-i)/2;
            
            int a=solve(n-1,mid-1,dp);
            int b=solve(n,k-mid,dp);
            if(b>a){
                i=mid+1;
            }else{
                j=mid-1;
            }
            
            ans=min(ans,1+max(a,b));
        
        }
        
        return dp[n][k]=ans;
    }
    
    
    int eggDrop(int n, int k) 
    {
        // your code here
        int dp[201][201];
        
        memset(dp,-1,sizeof(dp));
        
        solve(n,k,dp);
        
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends