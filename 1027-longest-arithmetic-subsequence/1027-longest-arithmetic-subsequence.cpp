class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
      int n = A.size(), ret = 2;
        vector<unordered_map<int, int>> dp(n, unordered_map<int, int>());
        
        for (int i = 1; i < n; ++i) {
            int curNum = A[i];
            for (int j = 0; j < i; ++j) {
                int diff = curNum - A[j];
                if (dp[j].find(diff) == dp[i].end()) {
                    dp[i][diff] = 2;
                } else {
                    dp[i][diff] = dp[j][diff] + 1;
                    ret = max(ret, dp[i][diff]);
                }
            }
        }
        
        return ret;
    
    }
};