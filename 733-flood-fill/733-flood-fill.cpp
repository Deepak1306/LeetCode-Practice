class Solution {
public:
void helper(vector<vector<int>>& image,int source,int sr, int sc, int newColor,int n,int m){
        
        
        if(sr<0 || sr>=n || sc<0 || sc>=m){
            return ;
        }
        
    if(image[sr][sc]==newColor || image[sr][sc]!=source){
        return ;
    }
    
         
         image[sr][sc]=newColor;
         
         helper(image,source,sr-1,sc,newColor,n,m);
         helper(image,source,sr,sc-1,newColor,n,m);
         helper(image,source, sr+1,sc,newColor,n,m);                     
         helper(image,source,sr,sc+1,newColor,n,m);
        
        return ;
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        
        helper(image,image[sr][sc],sr,sc,newColor,image.size(),image[0].size());
        
        return image;
    }
};