class Solution {
public:
    int num(vector<vector<int>>& board, int i, int j, int n, int m){
        int count=0;
        
        
        count+= i-1>=0 && board[i-1][j] ? 1 : 0;
        count+= i+1<n && board[i+1][j] ? 1 : 0;
        count+= j-1>=0 && board[i][j-1] ? 1 : 0;
        count+= j+1<m && board[i][j+1] ? 1 : 0;
        count+= i-1>=0 && j-1>=0 && board[i-1][j-1] ? 1 : 0;
        count+= i-1>=0 && j+1<m && board[i-1][j+1] ? 1 : 0;
        count+= i+1<n && j-1>=0 && board[i+1][j-1] ? 1 : 0;
        count+= i+1<n && j+1<m && board[i+1][j+1] ? 1 : 0;
        
        return count;
    
    }
    
    
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        
        vector<vector<int>>temp=board;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                int cnt=num(temp,i,j,n,m);
                
                if(board[i][j]==1){
                    
                    if(cnt<2 || cnt>3){
                        board[i][j]=0;
                    }
                    
                }else{
                    if(cnt==3){
                        board[i][j]=1;
                    }else{
                        board[i][j]=0;
                    }
                }
                
                
            }
        }
        
        
    }
};