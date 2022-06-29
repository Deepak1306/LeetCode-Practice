// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    int dfs(pair<int,int>adj[],int node,int &ans){
        if(!adj[node].first){
            return node;
        }
        
        ans=min(ans,adj[node].second);
        return dfs(adj,adj[node].first,ans);
    }
    
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        // code here
        pair<int,int>adj[n+1];
        int indeg[n+1];
        memset(indeg,0,sizeof(indeg));
        
        for(int i=0;i<p;i++){
            int u=a[i];
            int v=b[i];
            int w=d[i];
            
            adj[u]={v,w};
            
            indeg[v]++;
        }
        vector<vector<int>>arr;
        
        for(int i=1;i<=n;i++){
            if(indeg[i]==0 && adj[i].first){
                int start=adj[i].first;
                int ans=adj[i].second;
                
                int end=dfs(adj,start,ans);
                arr.push_back({i,end,ans});
                
                
            }
        }
        
        return arr;
        
        
    }
};


// { Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}  // } Driver Code Ends