class Solution {
public:
    void solve(vector<int>nums,vector<vector<int>>&ans,vector<int>& a,vector<bool>& vis){
        if(a.size()==nums.size()){
            ans.push_back(a);
            return ;
        }

        for(int k=0;k<nums.size();k++){
            if(vis[k]){
                continue;
            }
            vis[k]=true;
            a.push_back(nums[k]);
            solve(nums,ans,a,vis);
            vis[k]=false;
            a.pop_back();
           
        }
        
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>a;
        int n=nums.size();
        vector<bool>vis(n,false);
        solve(nums,ans,a,vis);
        return ans;
        
    }
};