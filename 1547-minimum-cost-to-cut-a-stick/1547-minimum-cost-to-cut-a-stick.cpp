int dp[101][101];

class Solution {
public:
    int solve(vector<int>& cuts, int i, int j){
         if(i>j){
         return 0;
         }
         
         if(dp[i][j]!=-1){
         return dp[i][j];
         }
         int cost=cuts[j+1]-cuts[i-1];
         int ans=INT_MAX;
         for(int k=i;k<=j;k++){
             int left=solve(cuts,i,k-1);
             int right=solve(cuts,k+1,j);
             
             int c=cost+left+right;
             
             ans=min(ans,c);
         }
         
         return dp[i][j]=ans;
    }
    
    int minCost(int n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
        cuts.push_back(0);
        cuts.push_back(n);
        
        sort(cuts.begin(),cuts.end());
        
        return solve(cuts,1,cuts.size()-2);
        
    }
};