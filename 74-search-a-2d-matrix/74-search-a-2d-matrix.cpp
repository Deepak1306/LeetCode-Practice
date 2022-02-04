class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        
       int i=0;
       int j=0;
       
        for(;i<n;i++){
            if(matrix[i][j]>target){
                break;
            }
        }
        
        i--;
        if(i<0){
            return false;
        }
        
        for(;j<m;j++){
            if(matrix[i][j]==target){
                return true;
            }
        }
        return false;
        
    }
};