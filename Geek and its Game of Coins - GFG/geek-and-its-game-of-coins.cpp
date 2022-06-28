// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int findWinner(int N, int X, int Y)
	{
		// Your code goes here
		if(X>Y){
		    swap(X,Y);
		}
		int dp[N+1];
		memset(dp,0,sizeof(dp));
		
		dp[1]=1;
		dp[X]=1;
		dp[Y]=1;
		
		for(int i=2;i<=N;i++){
		    if(i<X){
		        dp[i]=!dp[i-1];
		    }else if(i<Y){
		        dp[i]=!(dp[i-1] && dp[i-X]);
		    }else{
		        dp[i]=!(dp[i-1] && dp[i-X] && dp[i-Y]);
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