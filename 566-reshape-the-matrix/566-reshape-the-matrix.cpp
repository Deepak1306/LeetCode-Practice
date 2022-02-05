class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        int n=mat.size();
        int m=mat[0].size();
        
        
        
        if(r*c!=n*m){
            return mat;
        }
        
    vector<vector<int>>ans(r,vector<int>(c));       
        
        int k=0;
        int l=0;
        
        
       for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
             
             ans[k][l%c]=mat[i][j];
             l++;
             
             l%c==0? k++ : k;
          }
        
       }
        return ans;
        
        
    }
};