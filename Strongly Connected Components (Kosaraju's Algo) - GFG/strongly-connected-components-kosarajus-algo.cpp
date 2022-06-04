// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(vector<int> adj[],int node,vector<bool>& vis,stack<int>& st){
	    vis[node]=true;
	    
	    for(int j:adj[node]){
	        if(!vis[j]){
	            dfs(adj,j,vis,st);
	        }
	    }
	    
	    st.push(node);
	    
	}
	
	void scc(vector<int> transpose[],int node,vector<bool>& vis){
	    vis[node]=true;
	    
	    for(int j:transpose[node]){
	        if(!vis[j]){
	            scc(transpose,j,vis);
	        }
	    }
	    
	}
	
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector<bool>vis(V,false);
        stack<int>st;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(adj,i,vis,st);
            }
        }
        
        vector<int>transpose[V];
        
        for(int i=0;i<V;i++){
            vis[i]=false;
            for(int j:adj[i]){
                transpose[j].push_back(i);
            }
            
        }
        
        int count=0;
        while(!st.empty()){
            int f=st.top();
            st.pop();
            if(!vis[f]){
                scc(transpose,f,vis);
                count++;
            }
        }
        
        return count;
        
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends