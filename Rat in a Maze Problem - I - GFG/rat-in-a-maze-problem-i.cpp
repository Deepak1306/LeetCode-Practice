// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isValid(int i, int j,int n,vector<vector<int>> &m,vector<vector<bool>> vis){
        if(i<0 || i>=n || j<0 || j>=n || m[i][j]==0 || vis[i][j]==true){
            return false;
        } 
        
        return true;
    }
    
    void findPath(vector<vector<int>> &m, int n,vector<string>& ans,string s,int i,int j,vector<vector<bool>>& vis){
        if(i==n-1 && j==n-1){
            ans.push_back(s);
            return ;
        }else if(vis[i][j]==true || m[i][j]==0){
            return ;
        }
        vis[i][j]=true;
        
        if(isValid(i-1,j,n,m,vis)){
            findPath(m,n,ans,s+'U',i-1,j,vis);
            vis[i-1][j]=false;
        }
        if(isValid(i,j-1,n,m,vis)){
            findPath(m,n,ans,s+'L',i,j-1,vis);
            vis[i][j-1]=false;
        }
        if(isValid(i+1,j,n,m,vis)){
            findPath(m,n,ans,s+'D',i+1,j,vis);
            vis[i+1][j]=false;
        }
        if(isValid(i,j+1,n,m,vis)){
            findPath(m,n,ans,s+'R',i,j+1,vis);
            vis[i][j+1]=false;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>ans;
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        findPath(m,n,ans,"",0,0,vis);
        return ans;
        
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends