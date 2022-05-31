class Solution {
public:
    static bool compare(vector<int>a1,vector<int>a2){
        return a1[0]<a2[0];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),compare);
        
        int n=pairs.size();
        
        int ans=1;
        
        int dp[n];
        dp[0]=1;
        for(int i=1;i<n;i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(pairs[j][1]<pairs[i][0]){
                    dp[i]=max(dp[i],1+dp[j]);  
                }
                
                ans=max(ans,dp[i]);
            }
        }
        
        return ans;
        
    }
};