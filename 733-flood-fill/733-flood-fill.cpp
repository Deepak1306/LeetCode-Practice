class Solution {
public:
    
    
    void helper(vector<vector<int>>& image, int sr, int sc, int newColor,int n,int m, int source, vector<vector<bool>>&visited ){
      if(sr<0 || sr>=n || sc<0 || sc>=m ){
          return ;
      }else if(image[sr][sc]!=source || visited[sr][sc]){
          return ;
      }
        image[sr][sc]=newColor;
        visited[sr][sc]=true;
      
        helper(image ,sr-1,sc,newColor,n,m,source,visited);
        helper(image ,sr,sc-1,newColor,n,m,source,visited);
        helper(image ,sr,sc+1,newColor,n,m,source,visited);
        helper(image ,sr+1,sc,newColor,n,m,source,visited);
        
        return;
        
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        
       
        
        int n=image.size();
        int m=image[0].size();
        int source=image[sr][sc];
       
         vector<vector<bool>> visited(n,vector<bool>(m,false));
         
        
        helper(image,sr,sc,newColor,n,m,source,visited);
        
        return image;
        
    }
};