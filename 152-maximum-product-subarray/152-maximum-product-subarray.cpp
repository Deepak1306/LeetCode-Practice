class Solution {
public:
    int maxProduct(vector<int>& nums) {
       
        int ans=INT_MIN;
        int maxProd=nums[0];
        int minProd=nums[0];
        ans=max(maxProd,ans);
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                swap(minProd,maxProd);
            }
            
            maxProd=max(maxProd*nums[i],nums[i]);
            minProd=min(minProd*nums[i],nums[i]);
            
            ans=max(maxProd,ans);
        }
        
        return ans;
    }
};