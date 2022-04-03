class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n=nums.size();
        
        if(n==1){
            return ;
        }
        
        
        if(nums[n-1]>nums[n-2]){
            swap(nums[n-1],nums[n-2]);
            return ;
        }
            
        int i=n-2;
        int j=n-3;
        
        while(j>=0){
            if(nums[i]<=nums[j]){
                i--;
                j--;
                
            }else{
            
            int num=nums[j];
            sort(nums.begin()+i,nums.end());
            
            int k=i;
                while(num>=nums[k] && k!=n){
                    k++;
                }
            
            
            swap(nums[j],nums[k]);
            sort(nums.begin()+i,nums.end());
            
            return ;
            
          }
            
      }     
        sort(nums.begin(),nums.end());
        
        return ;
        
        
    }
};