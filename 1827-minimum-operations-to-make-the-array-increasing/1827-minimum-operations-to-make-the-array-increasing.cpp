class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        
        for(int i=1;i<n;i++){
           if(nums[i]<=nums[i-1]){
               count+=abs(nums[i-1]-nums[i])+1;
               nums[i]=nums[i]+abs(nums[i-1]-nums[i])+1;
           }    
        }
        
        return count;
        
        
    }
};