class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<bool>>&vis,int n,int m){
      if(i<0 || i>=n || j<0 || j>=m){
          return ;
      }
      
      if(grid[i][j]=='0' || vis[i][j]==true){
          return ;
      }
      
      vis[i][j]=true;
      
      dfs(i-1,j,grid,vis,n,m);
      dfs(i,j-1,grid,vis,n,m);
      dfs(i+1,j,grid,vis,n,m);
      dfs(i,j+1,grid,vis,n,m);
     
  }
    
    
    int numIslands(vector<vector<char>>& grid) {
       
        int n=grid.size();
        int m=grid[0].size();
        
        int count=0;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]==false){
                    dfs(i,j,grid,vis,n,m);
                    count++;
                }
            }
        }
        return count;
        
        
    }
};