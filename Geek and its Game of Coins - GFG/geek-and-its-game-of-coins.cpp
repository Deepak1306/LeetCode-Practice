// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int findWinner(int N, int x, int y)
	{
		// Your code goes here
		if(x>y){
		    swap(x,y);
		}
		int dp[N+1];
		memset(dp,0,sizeof(dp));
		
		dp[1]=1;
		dp[x]=1;
		dp[y]=1;
		
		for(int i=2;i<=N;i++){
		    if(i<x){
		        dp[i]=!dp[i-1];
		    }else if(i<y){
		        dp[i]=!(dp[i-1] && dp[i-x]);
		    }else{
		        dp[i]=!(dp[i-1] && dp[i-x] && dp[i-y]);
		    }
		}
		
		return dp[N];
	}

};
	

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
       	int n, x, y;
       	cin >> n >> x >> y;

       

        Solution ob;
        cout << ob.findWinner(n, x, y);
	    cout << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends