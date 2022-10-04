class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<int,int>>q;
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    count++;
                }
            }
        }
        int ans=0;
        while(!q.empty()){
            int s=q.size();
            
            while(s--){
                int x=q.front().first;
                int y=q.front().second;
                
                q.pop();
                
                if(x-1>=0 && grid[x-1][y]==1){
                    count--;
                    grid[x-1][y]=2;
                    q.push({x-1,y});
                }
                
                
                if(y-1>=0 && grid[x][y-1]==1){
                    count--;
                    grid[x][y-1]=2;
                    q.push({x,y-1});
                }
                
                
                if(x+1<n && grid[x+1][y]==1){
                    count--;
                    grid[x+1][y]=2;
                    q.push({x+1,y});
                }
                
                
                if(y+1<m && grid[x][y+1]==1){
                    count--;
                    grid[x][y+1]=2;
                    q.push({x,y+1});
                }
               
            }
            
            ans++;
        }
        
        
        if(count!=0){
            return -1;
        }
        
        if(ans==0){
            return ans;
        }
        return ans-1;
        
    }
};