class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        int n=arr.size();
        
        int m=arr[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=i;j<m;j++){
                int temp=arr[i][j];
                arr[i][j]=arr[j][i];
                arr[j][i]=temp;
            }
        }
        
        
        for(int i=0;i<n;i++){
            int l=0;
            int r=m-1;
            
            while(l<r){
                int temp=arr[i][l];
                arr[i][l]=arr[i][r];
                arr[i][r]=temp;
                l++;
                r--;
            }
            
        }
        
        return ;
        
    }
};