class Solution {
public:
    bool isBi(vector<vector<int>>graph,int node, vector<int>& color){
        queue<int>q;
        q.push(node);
        color[node]=0;
        
        while(!q.empty()){
            int f=q.front();
            q.pop();
            
            for(int j:graph[f]){
                if(color[j]==-1){
                    color[j]=!color[f];
                    q.push(j);
                }else if(color[j]==color[f]){
                    return false;
                }
            }
            
            
        }
        
        return true;
        
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        
        vector<int>color(n,-1);
        
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!isBi(graph,i,color)){
                    return false;
                }
            }
        }
        
        
      return true;  
    }
};