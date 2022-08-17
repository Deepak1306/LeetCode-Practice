class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int count=1;
        int i=1;

        
        for(int k=1;k<nums.size();k++){
           if(nums[k]==nums[k-1]){
               continue;
           }else{
               nums[i]=nums[k];
               count++;
               i++;
           }
        }
        
        return count;
    }
};