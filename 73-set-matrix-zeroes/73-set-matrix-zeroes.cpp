class Solution {
public:
    
    void col(vector<vector<int>>& matrix,int y,vector<vector<bool>>& arr){
        for(int i=0;i<matrix.size();i++){
            if(matrix[i][y]!=0){
                matrix[i][y]=0;
                arr[i][y]=true;
            }
        }
        
    }
    
    void row(vector<vector<int>>& matrix,int x,vector<vector<bool>>& arr){
        for(int i=0;i<matrix[0].size();i++){
            if(matrix[x][i]!=0){
                matrix[x][i]=0;
                arr[x][i]=true;
            }
        }
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
       vector<vector<bool>>arr(n,vector<bool>(m,false));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!arr[i][j] && matrix[i][j]==0){
                    row(matrix,i,arr);
                    col(matrix,j,arr);
                }
            }
        }
        
    }
};