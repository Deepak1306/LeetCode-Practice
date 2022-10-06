class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        
        vector<int>color(n,-1);
        
        for(int i=0;i<n;i++){
            if(color[i]!=-1){
                continue;
            }
            
            queue<pair<int,int>>q;
        
        q.push({i,0});
        color[i]=0;
        
        while(!q.empty()){
            int x=q.front().first;
            int c=q.front().second;
            
            q.pop();
            
            for(int j:graph[x]){
                if(color[j]==-1){
                   color[j]=!c;
                   q.push({j,color[j]}); 
                }else if(color[j]==c){
                    return false;
                }
            }
            
        }
        
        }
        
        return true;
    }
};