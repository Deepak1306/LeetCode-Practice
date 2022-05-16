// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
#include<unordered_map>

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& arr) {
        //code here
        unordered_map<string,int>m;
        int k=1;
        
        vector<vector<string>>ans;
        
        int n=arr.size();
        for(int i=0;i<n;i++){
            string s=arr[i];
            sort(s.begin(),s.end());
            
            if(m[s]!=0){
                ans[m[s]-1].push_back(arr[i]);
            }else{
                m[s]=k;
                ans.push_back({arr[i]});
                k++;
                
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
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends