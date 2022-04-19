class Solution {
public:
    
    
    void helper(vector<vector<int>>& image, int sr, int sc, int newColor,int n,int m, int source){
      if(sr<0 || sr>=n || sc<0 || sc>=m ){
          return ;
      }else if(image[sr][sc]!=source){
          return ;
      }
        image[sr][sc]=newColor;
      
        helper(image ,sr-1,sc,newColor,n,m,source);
        helper(image ,sr,sc-1,newColor,n,m,source);
        helper(image ,sr,sc+1,newColor,n,m,source);
        helper(image ,sr+1,sc,newColor,n,m,source);
        
        return;
        
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        if(newColor==image[sr][sc]){
            return image;
        }
        
        
        int n=image.size();
        int m=image[0].size();
        int source=image[sr][sc];
        
        helper(image,sr,sc,newColor,n,m,source);
        
        return image;
        
    }
};