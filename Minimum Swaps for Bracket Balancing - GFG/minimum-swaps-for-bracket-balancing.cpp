// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string s){
        // code here 
        
        int n=s.length();
        
        int ans=0;
        int c=0;
        
        for(int i=0;i<n;i++){
            if(s[i]=='['){
                c--;
            }else{
                c++;
                if(c>0){
                    ans+=c;
                }
            }
        }
        
        return ans;
        
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
}   // } Driver Code Ends