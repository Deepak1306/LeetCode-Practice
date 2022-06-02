// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool dfs(vector<int>adj[],int node,vector<int>&color){
        
        if(color[node]==-1){
         color[node]=0;    
        }
        
        for(int j:adj[node]){
            if(color[j]==-1){
                color[j]=!color[node];
                
                if(!dfs(adj,j,color)){
                    return false;
                }
                
            }else if(color[j]==color[node]){
                return false;
            }
        }
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int>color(V+1,-1);
	    
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            if(!dfs(adj,i,color)){
	                return false;
	            }
	        }
	    }
	    
	    return true;
	    
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends