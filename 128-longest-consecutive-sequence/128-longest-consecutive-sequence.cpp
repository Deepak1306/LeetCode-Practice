class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        if(nums.size()==0){
            return 0;
        }
        
        int count=1;
        int ans=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                continue;
            }else if(nums[i]!=1+nums[i-1]){
                count=1;
            }
            else{
                count++;
            }
            
            ans=max(ans,count);
        }
        
        return ans;
        
        
    }
};