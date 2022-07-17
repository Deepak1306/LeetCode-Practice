class Solution {
public:
    bool isSafe(vector<string> &v,int col,int i,int n){
        
        int x=col;
        int y=i;
        while(x>=0){
          if(v[y][x]=='Q'){
              return false;
          }
            x--;
        }
        
        x=col;
        while(x>=0 && y>=0){
            if(v[y][x]=='Q'){
                return false;
            }
            x--;
            y--;
        }
        
        x=col;
        y=i;
        while(x>=0 && y<n){
            if(v[y][x]=='Q'){
                return false;
            }
            x--;
            y++;
        }
        
        return true;
            
    }
    
    void solve(vector<string>&v,vector<vector<string>>&ans,int col,int n){
        if(col==n){
            ans.push_back(v);
            return ;
        }
        
        for(int i=0;i<n;i++){
            if(isSafe(v,col,i,n)){
                v[i][col]='Q';
                solve(v,ans,col+1,n);
                v[i][col]='.';
            }
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
       vector<vector<string>>ans;
        
        string str(n,'.');
        vector<string>v(n,str);
        
        solve(v,ans,0,n);
        return ans;
        
    }
};