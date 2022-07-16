class Solution {
public:
    void solve(vector<int>&nums , set<vector<int>>& ans, vector<int>a,int i){
        if(i==nums.size()){
            ans.insert(a);
            return ;
        }

        solve(nums,ans,a,i+1);
        a.push_back(nums[i]);
        solve(nums,ans,a,i+1);
        a.pop_back();
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>s;
         sort(nums.begin(),nums.end());
        
        vector<int>a;
        
        solve(nums,s,a,0);
        
        for(auto it:s){
            ans.push_back(it);
        }
        
        return ans;
    }
};