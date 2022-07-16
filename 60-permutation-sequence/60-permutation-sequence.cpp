class Solution {
public:
    
    
    void solve(int n,string &ans,string s,vector<bool>& vis, int& k){
        if(s.length()==n){
            k--;
            if(k==0){
                ans=s;
            }
            return ;
        }
        
        for(int i=1;i<=n;i++){
            if(vis[i]){
                continue;
            }
            vis[i]=true;
            char c=i+'0';
            s.push_back(c);
            solve(n,ans,s,vis,k);
            vis[i]=false;
            s.pop_back();
            
        }
        
    }
    
    string getPermutation(int n, int k) {
        string ans;
        vector<bool>vis(n+1,false);
        string s="";
        solve(n,ans,s,vis,k);
        
        return ans;
        
    }
};