class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        if(n<=2){
            return ans;
        }
        
        sort(nums.begin(),nums.end());
        
        set<vector<int>>s;
        
        
        for(int k=0;k<n-2;k++){
            int c=0-nums[k];
            int i=k+1;
            int j=n-1;
            
            while(i<j){
                
                if(c==nums[i]+nums[j]){
                    s.insert({nums[k],nums[i],nums[j]});
                    i++;
                    j--;
                }else if(c>nums[i]+nums[j]){
                    i++;
                }else{
                    j--;
                }
                
            }
            
        }
        
        for(auto i:s){
            ans.push_back(i);
        }
        
        return ans;
        
        
    }
};