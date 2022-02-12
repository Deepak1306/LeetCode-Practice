// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        // code here
        int start=0;
        int end=1;
        
        for(int i=0;i<s.length();i++){
            int l=i-1;
            int h=i;
            
            while(l>=0 && h<s.length() && s[l]==s[h]){
                if(h-l+1>end){
                    start=l;
                    end=h-l+1;
                }
                
                l--;
                h++;
            }
            
            l=i-1;
            h=i+1;
            
            while(l>=0 && h<s.length() && s[l]==s[h]){
                if(h-l+1>end){
                    start=l;
                    end=h-l+1;
                }
                
                l--;
                h++;
            }
            
            
        }
        
        string str=s.substr(start,end);
        return str;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends