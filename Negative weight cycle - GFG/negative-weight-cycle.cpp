// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    
	    vector<int>dist(n,INT_MAX);
	    
	    dist[0]=0;
	    
	    for(int i=1;i<n;i++){
	        
	        for(auto j:edges){
	            int u=j[0];
	            int v=j[1];
	            int wt=j[2];
	            
	            if(dist[u]!=INT_MAX && dist[u]+wt<dist[v]){
	                dist[v]=dist[u]+wt;
	            }
	        }
	    }
	    
	    int flag=0;
	    for(auto j:edges){
	            int u=j[0];
	            int v=j[1];
	            int wt=j[2];
	            
	            if(dist[u]!=INT_MAX && dist[u]+wt<dist[v]){
	                flag=1;
	                break;
	            }
	        }
	    
	    return flag;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends