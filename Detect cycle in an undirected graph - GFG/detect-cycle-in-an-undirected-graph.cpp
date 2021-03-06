// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool cycle(vector<int>adj[],int node, vector<bool>&vis){
        queue<pair<int,int>>q;
        q.push({node,-1});
        
        while(!q.empty()){
         int f=q.front().first;
         int p=q.front().second;
         q.pop();
         vis[f]=true;
         
         for(int j:adj[f]){
             if(!vis[j]){
                 q.push({j,f});
                 vis[j]=true;
             }else if(j!=p){
                 return true;
             }
         }
         
            
        }
        
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        vector<bool>vis(V,false);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(cycle(adj,i,vis)){
                    return true;
                }
            }
        }
        return false;
        
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends