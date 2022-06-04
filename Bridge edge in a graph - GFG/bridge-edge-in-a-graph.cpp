// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    bool dfs(vector<int> adj[],int parent,int node, int c, int d,vector<int>&disc,vector<int>&low,vector<bool>&vis, int&timer){
        disc[node]=timer;
        low[node]=timer;
        timer++;
        vis[node]=true;
        
        for(int j:adj[node]){
            if(j==parent){
                continue;
            }else if(!vis[j]){
                if(dfs(adj,node,j,c,d,disc,low,vis,timer)){
                    return true;
                }
                low[node]=min(low[node],low[j]);
                if(disc[node]<low[j]){
                    if((node==c && j==d)||(node==d && j==c)){
                        return 1;
                        
                    }
                }
            }else{
                low[node]=min(low[node],low[j]);
            }
            
            
        }
        
        return false;
    }
    
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        
        vector<int>disc(V,-1);
        vector<int>low(V,-1);
        vector<bool>vis(V,false);
        
        int timer=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(adj,-1,i,c,d,disc,low,vis,timer)){
                    return 1;
                }
            }
        }
        return 0;
        
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends