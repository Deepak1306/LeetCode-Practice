class Solution {
public:
    bool search(vector<int>& nums, int target) {
      
        int n=nums.size();
        int i=0;
        int j=n-1;
        
        while(i<=j){
            int mid=i+(j-i)/2;
            
            if(nums[mid]==target){
                return true;
            }
            
            else if(nums[mid]==nums[i] && nums[mid]==nums[j]){
                i++;
                j--;
                
            }else if(nums[mid]>=nums[i]){
                
                if(target>=nums[i] && nums[mid]>target){
                    j=mid-1;
                }else{
                    i=mid+1;
                }
            }else{
                if(target>nums[mid] && nums[j]>=target){
                    i=mid+1;
                }else{
                    j=mid-1;
                }
                
                
            }
            
            
        }
        
        return false;
        
        
    }
};