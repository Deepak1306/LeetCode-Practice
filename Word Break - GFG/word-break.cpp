// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int wordBreak(string A, vector<string> &B) {
        //code here
        unordered_map<string,int>m;
        int n=A.length();
        int dp[n];
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<B.size();i++){
            m[B[i]]=1;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                string s=A.substr(j,i-j+1);
               if(m.find(s)!=m.end()){
                   dp[i]=1;
                   if(j>0){
                       dp[i]=dp[i] && dp[j-1];
                   }
                   
                   if(dp[i]==1){
                       break;
                   }
               }
                
            }
        }
        
        return dp[n-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends