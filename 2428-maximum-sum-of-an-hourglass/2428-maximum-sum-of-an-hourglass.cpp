class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int n= grid.size();
        int m=grid[0].size();
        
        vector<vector<long long>>arr(n,vector<long long>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[i][j]=grid[i][j];
                
                if(j>0){
                arr[i][j]+=arr[i][j-1];    
                }
                
                if(i>0){
                    arr[i][j]+=arr[i-1][j];
                }
                
                if(i>0 && j>0){
                    arr[i][j]-=arr[i-1][j-1];
                }
                
                // cout<<arr[i][j]<<" ";
                
            }
            // cout<<endl;
        }
        
        long long ans=0;
        for(int i=2;i<n;i++){
            for(int j=2;j<m;j++){
                long long x=arr[i][j];
                
                if(i>2){
                    x-=arr[i-3][j];
                }
                
                if(j>2){
                    x-=arr[i][j-3];
                }
                
                if(i>2 && j>2){
                    x+=arr[i-3][j-3];
                }
                
                x-=(grid[i-1][j-2]+grid[i-1][j]);
                
                
                // cout<<arr[i][j]<<endl;
                
                ans=max(x,ans);
            }
        }
        
        return ans;
        
    }
};