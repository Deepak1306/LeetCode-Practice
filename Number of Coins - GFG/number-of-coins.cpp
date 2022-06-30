// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	static bool comp(int a, int b){
	    return a>b;
	}
	
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    
	    vector<int> dp(V+1,INT_MAX);
	    
	    
	    dp[0]=0;
	    for(int i=0;i<=V;i++){
	        if(dp[i]==INT_MAX){
	            continue;
	        }
	        
	        for(int j=0;j<M;j++){
	            if(coins[j]+i<=V){
	                dp[i+coins[j]]=min(dp[i+coins[j]],dp[i]+1);
	            }
	        }
	    }
	    
	    if(dp[V]==INT_MAX){
	        return -1;
	    }
	    
	    return dp[V];
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends