class Solution {
public:
    
    
    vector<int> findOrder(int n, vector<vector<int>>& arr) {
        
        vector<int>adj[n];
        
        for(int i=0;i<arr.size();i++){
            adj[arr[i][1]].push_back(arr[i][0]);
        }
        vector<int>ans;
        
        vector<int>indeg(n,0);
        for(int i=0;i<n;i++){
           for(int j:adj[i]){
               indeg[j]++;
           }
        }
        
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                ans.push_back(i);
                q.push(i);
            }
        }
        
        vector<bool>vis(n,false);
        while(!q.empty()){
            int f=q.front();
            
            q.pop();
            
            for(int j:adj[f]){
                if(!vis[j]){
                    indeg[j]--;
                    
                    if(indeg[j]==0){
                        q.push(j);
                        ans.push_back(j);
                    }
                }
            }
        }
        
        if(ans.size()==n){
            return ans;
        }
        
        return {};
        
        
    }
};