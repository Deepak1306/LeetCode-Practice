// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
int dp[201][201][2];

class Solution{
public:
    int solve(string s, int i, int j, int check){
        if(i>j){
            return 0;
        }
        
        if(i==j){
            if(check==1){
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
        
        if(dp[i][j][check]!=-1){
            return dp[i][j][check];
        }
        int ans=0;
        for(int k=i+1;k<j;k+=2){
            int lt=solve(s,i,k-1,1);
            int lf=solve(s,i,k-1,0);
            int rt=solve(s,k+1,j,1);
            int rf=solve(s,k+1,j,0);
            
            if(s[k]=='&'){
                if(check==true){
                    ans+=(lt*rt)%1003;
                }else{
                    ans+=((lf*rt)%1003+(lf*rf)%1003+(lt*rf)%1003)%1003;   
                }
                
            }
            else if(s[k]=='|'){
                if(check==true){
                    ans+=((lt*rf)%1003+(lt*rt)%1003+(lf*rt)%1003)%1003;
                }else{
                    ans+=(lf*rf)%1003;
                }
                
            }else if(s[k]=='^'){
                if(check==true){
                    ans+=((lt*rf)%1003+(lf*rt)%1003)%1003;
                }else{
                    ans+=((lt*rt)%1003+(rf*lf)%1003)%1003;
                }
                
            }
            
        }
        
        return dp[i][j][check]=ans%1003;
        
    }
    
    

    int countWays(int N, string S){
        // code here
   memset(dp,-1,sizeof(dp));
   
   return solve(S,0,N-1,true);
        
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