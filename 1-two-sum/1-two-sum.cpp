class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        
        int k=-1;
        int l=-1;
        for(int i=0;i<nums.size();i++){
            int n=target-nums[i];
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]==n){
                     k=i;
                     l=j;
                    break;
                    
                }
            }
        }
        
        vector<int>ans;
        
        ans.push_back(k);
        ans.push_back(l);
        return ans;
        
    }
};