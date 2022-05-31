// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
int dp[201][201][2];
class Solution{
public:
    int solve(int i, int j, string s, int isTrue){
        int mod=1003;
        if(i>j){
            return 0;
        }
        
        if(i==j){
            if(isTrue==1){
                if(s[i]=='T'){
                    return 1;
                }else{
                    return 0;
                }
                
            }else{
                if(s[i]=='F'){
                    return 1;
                }else{
                    return 0;
                }
            }
            
            
        }
        
        if(dp[i][j][isTrue]!=-1){
            return dp[i][j][isTrue];
        }
        int ans=0;
        
        for(int k=i+1;k<j;k+=2){
            int lt=solve(i,k-1,s,1);
            int lf=solve(i,k-1,s,0);
            int rt=solve(k+1,j,s,1);
            int rf=solve(k+1,j,s,0);
            
            if(s[k]=='^'){
                
                if(isTrue==1){
                 ans+=((lt*rf)%mod+(lf*rt)%mod)%mod;   
                }else{
                    ans+=((lt*rt)%mod+(lf*rf)%mod)%mod;
                }
            }else if(s[k]=='&'){
                if(isTrue==1){
                    ans+=((lt*rt)%mod)%mod;
                }else{
                    ans+=((lt*rf)%mod+(lf*rt)%mod+(lf*rf)%mod)%mod;
                }
            }else if(s[k]=='|'){
                if(isTrue==1){
                    ans+=((lf*rt)%mod+(lt*rf)%mod+(lt*rt)%mod)%mod;
                }else{
                    ans+=((lf*rf)%mod)%mod;
                }
            }
        }
        
        return dp[i][j][isTrue]=ans%mod;
        
        
        
        
        
        
    }

    int countWays(int N, string S){
        // code here
        memset(dp,-1,sizeof(dp));
        
        return solve(0,N-1,S,1);
        
        
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends