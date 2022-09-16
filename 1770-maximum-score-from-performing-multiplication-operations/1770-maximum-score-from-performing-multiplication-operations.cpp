class Solution {
public:
    vector<vector<int>>dp;
    
    int solve(vector<int>& nums, int i, int j,vector<int> &arr,int k){
        if(k==arr.size()){
            return 0;
        }else if(i>j){
            return 0;
        }else if(dp[i][k]!=INT_MIN){
            return dp[i][k];
        }
        int ans=nums[i]*arr[k]+solve(nums,i+1,j,arr,k+1);
        ans=max(ans,nums[j]*arr[k]+solve(nums,i,j-1,arr,k+1));

        return dp[i][k]=ans;
    }
    
    int maximumScore(vector<int>& nums, vector<int>& arr) {
        int n=nums.size();
        int m=arr.size();
        
       dp.resize(m+1,vector<int>(m+1,INT_MIN));
        
        return solve(nums,0,nums.size()-1,arr,0);
    }
};