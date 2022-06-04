// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isSafe(vector<vector<int>> &m, int x, int y,int n,vector<vector<bool>>&vis){
        if((x>=0 && x<n) &&(y>=0 && y<n) && vis[x][y]==false && m[x][y]==1){
            return true;
        }else{
            return false;
        }
        
    }
    
    void helper(vector<vector<int>> &m, int x, int y,int n, string out,vector<string>& ans,vector<vector<bool>>&vis){
        if(x==n-1 && y==n-1){
            ans.push_back(out);
            return ;
        }
        vis[x][y]=true;
        if(isSafe(m,x-1,y,n,vis)){
            out.push_back('U');
            helper(m,x-1,y,n,out,ans,vis);
            out.pop_back();
        }
        
        if(isSafe(m,x+1,y,n,vis)){
            out.push_back('D');
            helper(m,x+1,y,n,out,ans,vis);
            out.pop_back();
        }
        if(isSafe(m,x,y-1,n,vis)){
            out.push_back('L');
            helper(m,x,y-1,n,out,ans,vis);
            out.pop_back();
        }
        if(isSafe(m,x,y+1,n,vis)){
            out.push_back('R');
            helper(m,x,y+1,n,out,ans,vis);
            out.pop_back();
        }
        
        vis[x][y]=false;
        
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>ans;
        if(m[0][0]==0){
            return ans;
        }
        
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        
        helper(m,0,0,n,"",ans,vis);
        
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