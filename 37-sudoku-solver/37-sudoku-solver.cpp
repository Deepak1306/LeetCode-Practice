class Solution {
public:
    
    bool findrow(vector<vector<char>>& board,int x,int y,char c){
        for(int i=0;i<9;i++){
            if(board[i][y]==c){
                return false;
            }
            
        }
        
        return true;
    }
    
    bool findcol(vector<vector<char>>& board,int x,int y,char c){
        for(int i=0;i<9;i++){
            if(board[x][i]==c){
                return false;
            }
            
        }
        
        return true;
    }
    
    bool findgrid(vector<vector<char>>& board,int x,int y, char c){
        int a=x-(x%3);
        int b=y-(y%3);
        
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
              if(board[i+a][j+b]==c){
                  return false;
              }  
            }
        }
        return true;
    }
    bool findEmpty(vector<vector<char>>& board, int& row, int& col){
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    row=i;
                    col=j;
                    return true;
                }
            }
        }
        return false;
        
    }
    
    bool solve(vector<vector<char>>& board){
       
        int row;
        int col;
        if(!findEmpty(board,row,col)){
         return true;   
        }
        
        for(int i=1;i<=9;i++){
            char c=i+'0';
         if(findrow(board,row,col,c) && findcol(board,row,col,c) && findgrid(board,row,col,c)){
                 board[row][col]=c;
               if(solve(board)){
                   return true;
               }
               board[row][col]='.';
           }  
            
            
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        
       bool check =solve(board);
    }
};