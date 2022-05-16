// { Driver Code Starts
// C++ program to check if two strings are isomorphic
#include<iostream>
#include<string.h>

using namespace std;
#define MAX_CHARS 256

 // } Driver Code Ends
class Solution
{
    
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string s, string t)
    {
        
        // Your code here
        int n=s.length();
        int m=t.length();
        if(n!=m){
            return false;
        }
        
        char m1[256]={0};
        char m2[256]={0};
        
        for(int i=0;i<n;i++){
            if(!m1[s[i]] && !m2[t[i]]){
            m1[s[i]]=t[i];
            m2[t[i]]=s[i];
            }else if(m1[s[i]]!=t[i] || m2[t[i]]!=s[i]){
                return false;
            }
        }
        
        return true;
        
    }
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}  // } Driver Code Ends