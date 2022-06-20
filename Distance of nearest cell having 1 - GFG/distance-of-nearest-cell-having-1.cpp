// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    bool isSafe(int i,int j,int n,int m){
        if(i>=0 && i<n && j>=0 && j<m){
            return true;
        }
        
        return false;
    }
    
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n=grid.size();
	    int m=grid[0].size();
	    
	    vector<vector<int>>v(n,vector<int>(m,INT_MAX));
	    
	    queue<pair<int,int>>q;
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	                v[i][j]=0;
	                q.push({i,j});
	            }
	        }
	    }
	    
	    while(!q.empty()){
	        int x=q.front().first;
	        int y=q.front().second;
	        q.pop();
	        
	        if(isSafe(x-1,y,n,m) && v[x-1][y]>1+v[x][y]){
	            v[x-1][y]=1+v[x][y];
	            q.push({x-1,y});
	        }
	        if(isSafe(x,y-1,n,m) && v[x][y-1]>1+v[x][y]){
	            v[x][y-1]=1+v[x][y];
	            q.push({x,y-1});
	        }
	        if(isSafe(x+1,y,n,m) && v[x+1][y]>1+v[x][y]){
	            v[x+1][y]=1+v[x][y];
	            q.push({x+1,y});
	        }
	        if(isSafe(x,y+1,n,m) && v[x][y+1]>1+v[x][y]){
	            v[x][y+1]=1+v[x][y];
	            q.push({x,y+1});
	        }
	        
	        
	    }
	    
	    return v;
	    
	    
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends