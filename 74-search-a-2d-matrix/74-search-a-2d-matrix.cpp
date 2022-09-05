class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         
        int n=matrix.size();
        int m=matrix[0].size();
        
        int k=0;
        
        for(int i=0;i<n;i++){
            if(matrix[i][0]>target){
                break;
            }
            k=i;
            
        }
        
        int i=0;
        int j=m-1;
        
        while(i<=j){
            int mid=i+(j-i)/2;
            
            if(matrix[k][mid]==target){
                return true;
            }else if(matrix[k][mid]>target){
                j=mid-1;
            }else{
                i=mid+1;
            }
            
        }
        
        return false;
        
        
    }
};