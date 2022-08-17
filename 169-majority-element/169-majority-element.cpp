class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
     int i=0;
     int count=1;
        
        int j=0;
        
        while(j<nums.size()){
            if(nums[j]==nums[i]){
                count++;
            }else{
               count--;    
            }
            
            
            if(count==0){
                i=j;
                count=1;
            }
            j++;
        }
        return nums[i];
    }
};