// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        
        dp[0]=0;
        for(int i=0;i<=n;i++){
            
            if(dp[i]==-1){
                continue;
            }
            
            if(x+i<=n){
                dp[i+x]=max(dp[i+x],1+dp[i]);
            }
            if(y+i<=n){
                dp[i+y]=max(dp[i+y],1+dp[i]);
            }
            if(z+i<=n){
                dp[i+z]=max(dp[i+z],1+dp[i]);
            }
            
        }
        
        if(dp[n]==-1){
            return 0;
        }
        return dp[n];
        
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends