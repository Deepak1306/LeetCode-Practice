// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    bool isSafe(int i, int j, int n, int m,vector<vector<int>>& grid){
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j]==1){
            return true;
        }
        
        return false;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        
        int t=0;
        
        while(!q.empty()){
            int size=q.size();
            
            while(size>0){
                int x=q.front().first;
                int y=q.front().second;
                
                q.pop();
                
                if(isSafe(x-1,y,n,m,grid)){
                    q.push({x-1,y});
                    grid[x-1][y]=2;
                }
                if(isSafe(x,y-1,n,m,grid)){
                    q.push({x,y-1});
                    grid[x][y-1]=2;
                }
                if(isSafe(x+1,y,n,m,grid)){
                    q.push({x+1,y});
                    grid[x+1][y]=2;
                }
                if(isSafe(x,y+1,n,m,grid)){
                    q.push({x,y+1});
                    grid[x][y+1]=2;
                }
                size--;
            }
            if(!q.empty()){
            t++;    
            }
            
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        
        return t;
        
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends