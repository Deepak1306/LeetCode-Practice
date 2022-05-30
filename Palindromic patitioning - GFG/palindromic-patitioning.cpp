// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
int dp[501][501];
class Solution{
public:
bool isPalindrome(string s, int i, int j){
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    
    return true;
}
   
    int solve(int i,int j, string s){
        if(i>=j){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(isPalindrome(s,i,j)){
            return 0;
        }
        
        int ans=INT_MAX;
        
        for(int k=i;k<j;k++){
            if(isPalindrome(s,i,k)){
                int count=1+solve(k+1,j,s);
                ans=min(ans,count);
            }
        }
        
    return dp[i][j]=ans;
        
        
    }
    

    int palindromicPartition(string str)
    {
        // code here
        memset(dp,-1,sizeof(dp));
        int n=str.length();
        return solve(0,n-1,str);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends