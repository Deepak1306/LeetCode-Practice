class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        
        int i=0;
        int j=0;
        
        int sum=0;
        int ans=INT_MAX;
        while(i<n){
            sum+=nums[i];
            
           
            while(sum>=target){
                 ans=min(ans,i-j+1);
                sum-=nums[j];
                j++;
            }
            i++;
            
        }
        
        if(ans==INT_MAX){
            return 0;
        }
        return ans;
        
    }
};