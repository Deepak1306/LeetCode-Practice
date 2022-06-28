// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{


	public:
	long long getCount(int N)
	{
		// Your code goes here
		vector<vector<int>>arr={{0, 8},{1, 2, 4},{2, 1, 3, 5},{3, 2, 6},{4, 1, 5, 7},{5, 2, 4, 6, 8},{6, 3, 5, 9},{7, 8, 4},{8, 5, 7, 9, 0},{9, 6, 8}};
		
		
		long long dp[N+1][10];
		
		for(int i=0;i<=N;i++){
		    for(int j=0;j<10;j++){
		        if(i==0){
		            dp[i][j]=0;
		        }else if(i==1){
		            dp[i][j]=1;
		        }else{
		            dp[i][j]=0;
		            for(auto prev:arr[j]){
		                dp[i][j]+=dp[i-1][prev];
		            }
		            
		        }
		    }
		}
		
		long long ans=0;
		
		for(int i=0;i<10;i++){
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