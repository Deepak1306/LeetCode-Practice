class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        
        int i=1;
        int j=n;
        
        while(i<j){
            int mid=i+(j-i)/2;
            int count=0;
            
            
            for(int i=0;i<n;i++){
               if(nums[i]<=mid){
                   count++;
               } 
            }
            
            if(count>mid){
                j=mid;
            }else{
                i=mid+1;
            }
            
        }
        return i;
        
    }
};