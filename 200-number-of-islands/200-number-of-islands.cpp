class Solution {
public:
    
    void dfs(vector<vector<char>>& grid, int i, int j,vector<vector<bool>> &vis, int n,int m){
       if(i<0 || i>=n || j<0 || j>=m || grid[i][j]=='0'){
           return ;
       }
        if(vis[i][j]==true){
            return;
        }
        
        vis[i][j]=true;
        
        dfs(grid,i-1,j,vis,n,m);
        dfs(grid,i,j-1,vis,n,m);
        dfs(grid,i+1,j,vis,n,m);
        dfs(grid,i,j+1,vis,n,m);
        
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        
        
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(grid,i,j,vis,n,m);
                    count++;
                }
            }
        }
        return count;
        
        
    }
};