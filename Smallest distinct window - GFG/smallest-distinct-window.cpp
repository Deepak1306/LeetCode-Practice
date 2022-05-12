// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here  
        set<char>s;
        for(int i=0;i<str.length();i++){
            s.insert(str[i]);
        }
        int n=s.size();
        int c=0;
        
        unordered_map<char,int>m;
        int ans=INT_MAX;
        
        int i=0;
        m[str[i]]++;
        c++;
        
        int j=1;
        
        while(i<=j && j<str.length()){
            if(c<n){
              
              if(m[str[j]]==0){
                  c++;
              }
              m[str[j]]++;
              j++;
             
            }else if(c==n){
              ans=min(ans,j-i);
              
              if(m[str[i]]==1){
                  c--;
              }
              m[str[i]]--;
              i++;
              
              
            }
        }
        
        while(c==n){
             ans=min(ans,j-i);
              
              if(m[str[i]]==1){
                  c--;
              }
              m[str[i]]--;
              i++;
             
        }
        
        return ans;
        
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends