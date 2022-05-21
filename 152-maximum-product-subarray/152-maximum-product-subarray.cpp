class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int minimum=1;
        int maximum=1;
        
        int ans=INT_MIN;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                swap(minimum,maximum);
            }
            
            maximum=max(nums[i]*maximum,nums[i]);
            minimum=min(nums[i]*minimum,nums[i]);
            
            ans=max(maximum,ans);
        }
        
        return ans;
    }
};