class Solution {
public:
    void dfs(vector<int>adj[],int node,vector<bool>& vis){
        vis[node]=true;
        
        for(int j:adj[node]){
            if(!vis[j]){
                dfs(adj,j,vis);
            }
        }
    }
    
    
    int makeConnected(int n, vector<vector<int>>& connections) {
       int edges=0;
        
        if(n==0){
            return -1;
        }
        
        vector<int>adj[n];
        
        for(int i=0;i<connections.size();i++){
            int a=connections[i][0];
            int b=connections[i][1];
            edges++;
            
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        
        vector<bool>vis(n,false);
        int count=0;
        for(int i=0;i<n;i++){
           if(!vis[i]){
             dfs(adj,i,vis);
               count++;
            }
           
        }
        
        if(edges<n-1){
            return -1;
        }
        
        int red=edges-((n-1)-(count-1));
        if(red>=count-1){
            return count-1;
        }
        
        return -1;
        
        
        
        
    }
};