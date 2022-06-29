class Solution {
public:
    bool solve(vector<int>adj[],int node,vector<bool>&vis,vector<bool>&dfs){
        vis[node]=true;
        dfs[node]=true;
        for(int j:adj[node]){
            
            for(int i:adj[j]){
                if(i==node){
                    return true;
                }
            }
            
            if(!vis[j]){
                if(solve(adj,j,vis,dfs)){
                    return true;
                }
                
            }else if(dfs[j]==true){
                return true;
            }
            
            
        }
        
        dfs[node]=false;
        return false;
        
        
        
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<bool>vis(numCourses,false);
        vector<bool>dfs(numCourses,false);

        vector<int>adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            
            adj[u].push_back(v);
            
        }
        
        
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(solve(adj,i,vis,dfs)){
                    return false;
                }
            }
        }
        return true;
        
    }
};