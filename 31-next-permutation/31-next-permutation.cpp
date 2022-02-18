class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        
        if(nums.size()==0 || nums.size()==1){
            return;
        }
        
        
        if(nums[n-1]>nums[n-2]){
            int temp=nums[n-2];
            nums[n-2]=nums[n-1];
            nums[n-1]=temp;
            return ;
        }
        
        if(n==2){
            sort(nums.begin(),nums.end());
            return;
        }
        
        int i=n-2;
        int j=n-3;
        
        while(j>=0){
          if(nums[j]>=nums[i]){
             i--;
             j--;
              
          }else{
              int num=nums[j];
              sort(nums.begin()+j+1,nums.end());
              
              int k=j+1;
              while(nums[k]<=num && k!=n){
                  k++;
              }
              swap(nums[k],nums[j]);
              
              sort(nums.begin()+i,nums.end());
              return ;
              
          }   
            
        }
        
         sort(nums.begin(),nums.end());

         return ;
        
    }
};