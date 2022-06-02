class Solution {
public:
    void setcols(vector<vector<int>>& matrix,int j,int n,vector<vector<bool>>& visited){
        
        for(int i=0;i<n;i++){
            if(matrix[i][j]!=0){
             visited[i][j]=true; 
             matrix[i][j]=0;
            }
        }
        
        
    }
    void setrows(vector<vector<int>>& matrix,int i,int m,vector<vector<bool>>& visited){
        for(int j=0;j<m;j++){
            
            if(matrix[i][j]!=0){
              matrix[i][j]=0;
            visited[i][j]=true;  
            }
            
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
                    setcols(matrix,j,n,visited);
                    setrows(matrix,i,m,visited);
                }
            }
        }
        
        
    }
};