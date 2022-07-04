class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int i,int j, int n, int m){
       
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j]==1){
            return true;
        }
        
        return false;
        
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<int,int>>q;
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        
        int t=0;
        
        while(!q.empty()){
            int size=q.size();
            
            while(size--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                
                if(isValid(grid,x-1,y,n,m)){
                    q.push({x-1,y});
                    grid[x-1][y]=2;
                }
                
                if(isValid(grid,x,y-1,n,m)){
                     q.push({x,y-1});
                    grid[x][y-1]=2;
                }
                
                if(isValid(grid,x+1,y,n,m)){
                     q.push({x+1,y});
                    grid[x+1][y]=2;
                }
                
                if(isValid(grid,x,y+1,n,m)){
                     q.push({x,y+1});
                    grid[x][y+1]=2;
                }
                
            }
            t++;
            
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        
        if(t==0){
            return 0;
        }
        
        return t-1;
        
        
        
    }
};