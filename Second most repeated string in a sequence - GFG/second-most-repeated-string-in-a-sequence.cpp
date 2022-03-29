// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
  public:
    
    static bool comp(pair<string,int>a1,pair<string,int>a2){
        return a1.second>a2.second;
    }
    
    string secFrequent (string arr[], int n)
    {
        //code here.
        unordered_map<string,int>map;
        for(int i=0;i<n;i++){
            map[arr[i]]++;
        }
        
        vector<pair<string,int>>a(map.begin(),map.end());
        
        sort(a.begin(),a.end(),comp);
        
        return a[1].first;
        
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends