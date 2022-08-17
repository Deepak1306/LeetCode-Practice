class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        if(target<matrix[0][0]){
            return false;
        }
        
        int k=0;
        for(int i=0;i<n;i++){
            if(matrix[i][0]>target){
                break;
            }
            k=i;
        }
        
        
        int l=0;
        int h=m-1;
        
        while(l<=h){
            int mid=l + (h-l)/2;
            
            if(matrix[k][mid]==target){
                return true;
            }
            else if(matrix[k][mid]<target){
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        
        return false;
        
    }
};