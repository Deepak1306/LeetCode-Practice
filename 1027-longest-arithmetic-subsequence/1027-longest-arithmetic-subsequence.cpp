class Solution {
public:
    int longestArithSeqLength(vector<int>&A) {
        int n = A.size();
        int result = 0;
        vector<vector<int>> dp(n,vector<int>(20000,0));
        
        for (int i = 1; i < n; i++) {
            int currNum=A[i];
            for (int j = 0; j < i; j++) {
                int diff = currNum-A[j]+1000;
                dp[i][diff]=max(dp[j][diff]+1,2);
                
                result=max(result,dp[i][diff]);
               
            }
        }
        return result;
    }
};