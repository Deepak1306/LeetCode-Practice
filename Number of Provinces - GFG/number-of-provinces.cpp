// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void bfs(vector<vector<int>> adj,int i,vector<bool>& vis,int V){
        queue<int>q;
        
        q.push(i);
        vis[i]=true;
        while(!q.empty()){
            int f=q.front();
            q.pop();
            
            for(int j=0;j<V;j++){
                if(!vis[j] && adj[f][j]==1){
                    q.push(j);
                    vis[j]=true;
                }
            }
            
            
        }
        
    }
  
  
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<bool>vis(V+1,false);
        int count=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                bfs(adj,i,vis,V);
                count++;
            }
        }
        
        return count;
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}  // } Driver Code Ends