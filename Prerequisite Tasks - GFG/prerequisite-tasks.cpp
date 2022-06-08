// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    
	    vector<int>adj[N];
	    vector<int>indeg(N);
	     
	    for(int i=0;i<prerequisites.size();i++){
	        int u=prerequisites[i].first;
	        int v=prerequisites[i].second;
	    
	        adj[u].push_back(v);
	        indeg[v]++;
	    }
	    
	    vector<int>topo;
	         
	         queue<int>q;
	   
	    for(int i=0;i<N;i++){
	        if(indeg[i]==0){
	            q.push(i);
	        }
	    }
	    
	     while(!q.empty()){
	         int f=q.front();
	         q.pop();
	         topo.push_back(f);
	         
	         for(int j:adj[f]){
	             indeg[j]--;
	             
	             if(indeg[j]==0){
	                 q.push(j);
	             }
	             
	             
	         }
	         
	         
	         
	     }
	    if(topo.size()==N){
	        return true;
	    }
	    
	    return false;
	    
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends