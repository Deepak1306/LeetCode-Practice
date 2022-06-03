// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    void deg(vector<int>adj[],int n,vector<int>& indeg){
	    for(int i=0;i<n;i++){
	        for(int j:adj[i]){
	            indeg[j]++;
	        }
	    }
	}
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>indeg(V+1,0);
	    deg(adj,V,indeg);
	    int count=0;
	    
	    queue<int>q;
	    for(int i=0;i<V;i++){
	        if(indeg[i]==0){
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int f=q.front();
	        q.pop();
	        
	        count++;
	        
	        for(int j:adj[f]){
	            indeg[j]--;
	            
	            if(indeg[j]==0){
	                q.push(j);
	            }
	        }
	    }
	    
	    
	    if(count==V){
	        return false;
	    }
	    return true;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends