class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
       
       int dp[10001]={0};
        
        for(int i=0;i<nums.size();i++){
            dp[nums[i]]++;
        }
        
        int exc=0;
        int inc=0;
        
        for(int i=0;i<=10000;i++){
            int count=max(exc,inc);
            inc=dp[i]*i+exc;
            exc=count;
        }
      
        return max(inc,exc);
        
    }
};