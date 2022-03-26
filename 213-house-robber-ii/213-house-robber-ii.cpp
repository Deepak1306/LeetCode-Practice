class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0]; 
        }else if(n==2){
            return max(nums[0],nums[1]);
        }
        
        int dp[n-1];
        int dp1[n-1];
        
        for(int i=0;i<n-1;i++){
            dp[i]=0;
            dp1[i]=0;
        }
        
           dp[0]=nums[0];
           dp[1]=max(nums[0],nums[1]);
           for(int i=2;i<n-1;i++){
               dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
           }
        
           dp1[0]=nums[1];
           dp1[1]=max(nums[1],nums[2]);
           for(int i=3;i<n;i++){
               dp1[i-1]=max(dp1[i-2],nums[i]+dp1[i-3]);
           }
        
        
        return max(dp[n-2],dp1[n-2]);
        
    }
};