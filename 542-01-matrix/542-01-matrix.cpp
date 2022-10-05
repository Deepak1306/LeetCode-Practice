class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<int>>ans(n,vector<int>(m,INT_MAX));
        
        queue<pair<int,pair<int,int>>>q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({0,{i,j}});
                    ans[i][j]=0;
                }
            }
        } 
        
        
        while(!q.empty()){
            int d=q.front().first;
            int i=q.front().second.first;
            int j=q.front().second.second;
            
            q.pop();
            
            if(i-1>=0 && mat[i-1][j]!=0 && ans[i-1][j]>d+1){
                 ans[i-1][j]=d+1;
                 q.push({d+1,{i-1,j}});
            }
            
            if(j-1>=0 && mat[i][j-1]!=0 && ans[i][j-1]>d+1){
                 ans[i][j-1]=d+1;
                 q.push({d+1,{i,j-1}});
            }
            
            if(i+1<n && mat[i+1][j]!=0 && ans[i+1][j]>d+1){
                 ans[i+1][j]=d+1;
                 q.push({d+1,{i+1,j}});
            }
            
            if(j+1<m && mat[i][j+1]!=0 && ans[i][j+1]>d+1){
                 ans[i][j+1]=d+1;
                 q.push({d+1,{i,j+1}});
            }
            
             
            
        }
                           
       return ans;
        
        
    }
};