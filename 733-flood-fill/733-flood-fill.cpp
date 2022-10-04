class Solution {
public:
    
    void dfs(vector<vector<int>> &arr, int i,int j, int n,int m, int color, vector<vector<bool>>&vis, int x){
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j] || arr[i][j]==color || arr[i][j]!=x){
            return ;
        }
        
        vis[i][j]=true;
        arr[i][j]=color;
        dfs(arr,i-1,j,n,m,color,vis,x);
        dfs(arr,i,j-1,n,m,color,vis,x);
        dfs(arr,i+1,j,n,m,color,vis,x);
        dfs(arr,i,j+1,n,m,color,vis,x);
        
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n=image.size();
        int m=image[0].size();
        
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        
        dfs(image,sr,sc,n,m,color,vis, image[sr][sc]);
        return image;
    }
};