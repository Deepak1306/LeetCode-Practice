// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
   int dp[101][101];
class Solution{
    public:
    int solve(int i, int j, int k, vector<int>& a){
        if(i>j){
            return 0;
        }
        
        if(a[j]-a[i]<=k){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int a1=solve(i+1,j,k,a);
        int a2=solve(i,j-1,k,a);
        
        return dp[i][j]=1+min(a1,a2);
        
        
    }
    
    int removals(vector<int>& a, int k){
        //Code here
        sort(a.begin(),a.end());
     
        memset(dp,-1,sizeof(dp));
        
        return solve(0,a.size()-1,k,a);
        
    }
};


// { Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.removals(a,k);
        
        cout<<ans<<endl;
    }
}


  // } Driver Code Ends