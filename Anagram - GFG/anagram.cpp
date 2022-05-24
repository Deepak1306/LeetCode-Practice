// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        // Your code here
        if(a.length()!=b.length()){
            return false;
        }
        
       unordered_map<char,int>m1;
       unordered_map<char,int>m2;
       
       for(int i=0;i<a.length();i++){
           m1[a[i]]++;
           m2[b[i]]++;
       }
       
       
       for(int i=0;i<a.length();i++){
           if(m2.find(a[i])==m2.end() || m1.find(b[i])==m1.end() || m2[b[i]]!=m1[b[i]] || m2[a[i]]!=m1[a[i]]){
               return false;
           }
       }
       
       return true;
    }

};

// { Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}
  // } Driver Code Ends