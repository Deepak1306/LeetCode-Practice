class Solution {
public:
    void setCol(int i, vector<vector<bool>>& visited, int m,vector<vector<int>>& matrix){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){continue;}
            visited[i][j]=true;
            matrix[i][j]=0;
        }
    }
    
    
    void setRow(int j, vector<vector<bool>>& visited,int n,vector<vector<int>>& matrix){
        for(int i=0;i<n;i++){
            if(matrix[i][j]==0){continue;}
            visited[i][j]=true;
            matrix[i][j]=0;
        }
        
        
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && matrix[i][j]==0){
                    visited[i][j]=true;
                    setCol(i,visited,m,matrix);
                    setRow(j,visited,n,matrix);
                }
            }
        }
        
      return ;  
        
    }
};