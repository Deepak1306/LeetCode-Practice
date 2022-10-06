class Solution {
public:   
    void dfs(vector<vector<char>>& arr, int i, int j, int n, int m, vector<vector<bool>> &vis){
        if(i<0 || i>=n || j<0 || j>=m){
            return ;
        }
        else if(vis[i][j] || arr[i][j]=='X'){
            return ;
        }
        
        arr[i][j]='F';
        vis[i][j]=true;
        dfs(arr,i-1,j,n,m,vis);
        dfs(arr,i+1,j,n,m,vis);
        dfs(arr,i,j-1,n,m,vis);
        dfs(arr,i,j+1,n,m,vis);
        
    }
    
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        
        
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        
        for(int j=0;j<m;j++){
            
            if(board[0][j]=='O'){
              dfs(board,0,j,n,m,vis);    
            }
            
            if(board[n-1][j]=='O'){
                 dfs(board,n-1,j,n,m,vis);
            }
            
        }
        
        for(int i=0;i<n;i++){
            
            if(board[i][0]=='O'){
               dfs(board,i,0,n,m,vis);
            }
            
            if(board[i][m-1]=='O'){
               dfs(board,i,m-1,n,m,vis);
            }
            
            
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='F'){
                    board[i][j]='O';
                }else{
                    board[i][j]='X';
                }
            }
        }
        
        
    }
};