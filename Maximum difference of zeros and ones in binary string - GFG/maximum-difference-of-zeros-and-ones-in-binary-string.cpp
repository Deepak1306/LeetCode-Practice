// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	    // Your code goes here
	    int n=S.length();
	    int dp[n];
	    
	    for(int i=0;i<n;i++){
	        if(S[i]=='0'){
	            dp[i]=1;
	        }else{
	            dp[i]=-1;
	        }
	    }
	    
	    int ans=dp[0];
	    int currSum=dp[0];
	    
	    for(int i=1;i<n;i++){
	      if(currSum<dp[i]){
	         currSum=dp[i];
	      }else{
	          currSum+=dp[i];
	      }  
	       ans=max(ans,currSum);
	    }
	    
	    
	    return ans;
	    
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends