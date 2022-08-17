class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n=nums.size();
        
        int i=0;
        int k=n-1;
        
        int j=0;
        while(j<n){
            if(nums[j]==0 && i!=j){
                swap(nums[j],nums[i]);
                i++;
                continue;
            }else if(nums[j]==2 && j<k){
                swap(nums[k],nums[j]);
                k--;
                continue;
            }
            j++;
        }
        
    }
};