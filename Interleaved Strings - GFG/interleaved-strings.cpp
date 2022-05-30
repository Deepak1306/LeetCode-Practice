// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
int dp[201][201][201];
class Solution{
  public:
    /*You are required to complete this method */
    bool solve(string A, string B, string C){
        int a=A.length();
        int b=B.length();
        int c=C.length();
        
        if(c==0){
            return 1;
        }
        
        if(a==0 && b==0){
            return 0;
        }
        
        if(a==0 && B[0]!=C[0] || b==0 && A[0]!=C[0]){
         return 0;   
        }
        
        
        if(dp[a][b][c]!=-1){
            return dp[a][b][c];
        }
        int n=0;
        int m=0;
        if(A[0]==C[0]){
            n=solve(A.substr(1),B,C.substr(1));
        }
        
        if(B[0]==C[0]){
            m=solve(A,B.substr(1),C.substr(1));
        }
        
        return dp[a][b][c]=n||m;
        
    }
    
    
    bool isInterleave(string A, string B, string C) 
    {
        //Your code here
        memset(dp,-1,sizeof(dp));
        
        
        if(solve(A,B,C)==1){
            return true;
        }else{
            return false;
        }
        
        
    }

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends