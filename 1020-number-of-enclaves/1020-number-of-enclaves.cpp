class Solution {
public:
    
    void dfs(vector<vector<int>>& arr, int i, int j, int n,int m,vector<vector<bool>> &vis){
        if(i<0 || i>=n || j<0 || j>=m){
            return ;
        }else if(vis[i][j] || arr[i][j]==0){
            return ;
        }
        
        vis[i][j]=true;
        arr[i][j]=0;
        
        dfs(arr,i-1,j,n,m,vis);
        dfs(arr,i+1,j,n,m,vis);
        dfs(arr,i,j-1,n,m,vis);
        dfs(arr,i,j+1,n,m,vis);
        
    }
    
    
    int numEnclaves(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        int count=0;
        
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
          if(grid[i][0]==1){
              dfs(grid,i,0,n,m,vis);
          }
           
          if(grid[i][m-1]==1){
              dfs(grid,i,m-1,n,m,vis);
          }
        }
        
        for(int j=0;j<m;j++){
           if(grid[0][j]==1){
              dfs(grid,0,j,n,m,vis);
          }
           
          if(grid[n-1][j]==1){
              dfs(grid,n-1,j,n,m,vis);
          } 
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        
        return count;
        
    }
};