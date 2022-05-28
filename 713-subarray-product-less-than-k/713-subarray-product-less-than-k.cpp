class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count=0;
        int n=nums.size();
        
        int j=0;
        int prod=1;
        for(int i=0;i<n;i++){
           
            prod*=nums[i];
            
            while(prod>=k && j<=i){
                prod=prod/nums[j];
                j++;
            }
            
            count+=(i-j)+1;
            
            
        }
        
        
        return count;
       
    }
};