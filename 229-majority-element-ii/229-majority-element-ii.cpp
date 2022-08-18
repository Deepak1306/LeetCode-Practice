class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       sort(nums.begin(),nums.end());
        
        int n=nums.size();
        
        
        vector<int>ans;
        int count=1;
        
        for(int i=1;i<n;i++){
         if(nums[i]!=nums[i-1]){
             if(count>n/3){
                 ans.push_back(nums[i-1]);
             }
             
             count=1;
         }else{
             count++;
         }
            
        }
        if(count>n/3){
            ans.push_back(nums[n-1]);
        }
        
        return ans;
        
    }
};