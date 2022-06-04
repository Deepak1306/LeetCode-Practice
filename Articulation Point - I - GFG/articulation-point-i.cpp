// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++


class Solution {
  public:
  
  void dfs(vector<int>adj[],int node,int parent,int& timer,vector<int>&disc,vector<int>&low,vector<bool>&vis,vector<int>&ans){
      
      vis[node]=true;
      disc[node]=low[node]=timer;
      timer++;
      int child=0;
      
      for(int j:adj[node]){
          if(j==parent){
              continue;
          }else if(!vis[j]){
              dfs(adj,j,node,timer,disc,low,vis,ans);
              low[node]=min(low[node],low[j]);
              
              if(disc[node]<=low[j] && parent!=-1){
                  ans[node]=1;
              }
              child++;
          }else{
              low[node]=min(low[node],disc[j]);
          }
          
          
      }
      
      if(parent==-1 && child>1){
          ans[node]=1;
      }
      
      
  }
  
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int>disc(V,-1);
        vector<int>low(V,-1);
        vector<bool>vis(V,false);
        
    
        int timer=1;
        vector<int>ans(V,-1);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(adj,i,-1,timer,disc,low,vis,ans);
            }
        }
        
        vector<int> art;
        for(int i=0;i<V;i++){
            if(ans[i]!=-1){
                art.push_back(i);
            }
        }
        if(art.size()==0){
            art.push_back(-1);
            return art;
        }
        return art;
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
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends