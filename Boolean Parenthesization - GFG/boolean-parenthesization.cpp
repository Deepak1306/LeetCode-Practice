// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
int dp[500][500][2];
class Solution{
public:
    int count(string s, int i,int j,int isTrue,vector<vector<vector<int>>> &dp){
        if(i>j){
            return 0;
        }
        
       int mod=1003;
        
        if(i==j){
            if(isTrue==1){
                if(s[i]=='T'){
                    return 1;
                }else{
                    return 0;
                }
            }else if(isTrue==0){
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
            int lt=count(s,i,k-1,1,dp);
            int lf=count(s,i,k-1,0,dp);
            int rt=count(s,k+1,j,1,dp);
            int rf=count(s,k+1,j,0,dp);
            
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
        
        vector<vector<vector<int>>> dp(N,vector<vector<int>>(N,vector<int>(2,-1)));
        
        return count(S,0,N-1,1,dp);
        
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