// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	
	public:
	
	long long getCount(int N)
	{
		// Your code goes here
		vector<vector<int>>paths={{0,8}, {1,2,4}, {1,2,3,5}, {2,6,3}, {1,4,5,7}, {2,4,5,6,8}, {3,5,9,6}, {4,7,8}, {7,5,8,0,9}, {8,6,9}};
		
		long long dp[N+1][10];
		
		for(int i=0;i<=N;i++){
		    for(int j=0;j<=9;j++){
		        if(i==0){
		            dp[i][j]=0;
		        }else if(i==1){
		            dp[i][j]=1;
		        }else{
		            dp[i][j]=0;
		            for(int prev:paths[j]){
		                dp[i][j]+=dp[i-1][prev];
		            }
		            
		        }
		        
		        
		    }
		}
		
		long long ans=0;
		for(int i=0;i<=9;i++){
		    ans+=dp[N][i];
		}
		
		return ans;
		
	}


};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends