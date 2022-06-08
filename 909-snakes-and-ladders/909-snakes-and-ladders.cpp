class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
       
        int N=n*n;
        
        int adj[N];
        
        int k=0;
        int i=n-1;
        int j=0;
        int inc=1;
        
        while(k<N){
            adj[k]=board[i][j];
            
            if(board[i][j]!=-1){
                adj[k]=board[i][j]-1;
            }
            
            if(inc==1 && j==n-1){
                inc=-1;
                i--;
            }else if(inc==-1 && j==0){
                inc=1;
                i--;
            }else{
                j+=inc;
            }
            
            k++;
            
        }
        
        
        
        
        
        
        vector<bool>vis(N,false);
        
        queue<pair<int,int>>q;
        
        
        int start=adj[0]> -1? adj[0]:0;
        q.push({start,0});
        vis[start]=true;
        
        while(!q.empty()){
            int v=q.front().first;
            int d=q.front().second;
            q.pop();
             
        
            if(v==N-1){
                return d;
            }
            
            for(int i=v+1;i<=v+6 && i<N;i++){
                
                int dest=i;
                
                if(adj[i]!=-1){
                    dest=adj[i];
                }
               
               
                if(!vis[dest]){
                    vis[dest]=true;
                    q.push({dest,d+1});
                }
                
                
                
            }
        }
        
        return -1;
        
        
    }
};