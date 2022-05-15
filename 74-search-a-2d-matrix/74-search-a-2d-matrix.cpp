class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        
        int in=0;
        for(int i=1;i<n;i++){
           if(target<matrix[i][0]){
               break;
           } 
            in=i;
        }
        
        
        for(int j=0;j<m;j++){
            if(target==matrix[in][j]){
                return true;
            }
        }
        
        return false;
    }
};