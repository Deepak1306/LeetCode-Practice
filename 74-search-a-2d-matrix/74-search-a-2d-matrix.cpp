class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int n=matrix.size();
        
        int m=INT_MAX;
        
        for(int i=0;i<n;i++){
            if(target==matrix[i][0]){
                return true;
            }
            
            if(target<matrix[i][0]){
                m=i-1;
                break;
            }
        }
        
        if(m<0){
            m=0;
        }else if(m==INT_MAX){
            m=n-1;
        }
        
        int j=0;
        int k=matrix[0].size()-1;
        
        while(j<=k){
            int mid=j+(k-j)/2;
            
            if(matrix[m][mid]==target){
                return true;
            }else if(matrix[m][mid]>target){
                k=mid-1;
            }else{
                j=mid+1;
            }
            
        }
        
        return false;
        
        
    }
};