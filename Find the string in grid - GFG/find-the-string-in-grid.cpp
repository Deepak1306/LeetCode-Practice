// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool dfs(vector<vector<char>>grid, string word,int i,int j,int n,int m){
        
        vector<vector<int>>dirs={{-1,0},{0,-1},{-1,-1},{-1,1},{1,-1},{1,0},{1,1},{0,1}};
        
         for(auto dir:dirs){
              int newi=i;
              int newj=j;
              int k=0;
              
             while(newi>=0 && newj>=0 && newj<m && newi<n && k<word.length() && grid[newi][newj]==word[k]){
                 newi+=dir[0];
                 newj+=dir[1];
                 k++;
             }
             
             if(k==word.length()){
                 return true;
             }
         }
        
        return false;
            
    }

    
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    int n=grid.size();
	    int m=grid[0].size();
	    int l=word.length();
	    
	    vector<vector<int>> ans;
	    
	    for(int i=0;i<n;i++){
	       for(int j=0;j<m;j++){
	           if(word[0]==grid[i][j] && dfs(grid,word,i,j,n,m)){
	               ans.push_back({i,j});
	           }
	       }      
	    }
	    
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
	}
	return 0;
}  // } Driver Code Ends