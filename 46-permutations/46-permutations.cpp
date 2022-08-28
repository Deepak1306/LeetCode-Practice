class Solution {
public:
    
    void solve(vector<int>&nums,vector<vector<int>>&ans,vector<int> &a,map<int,int>&m){
        if(a.size()==nums.size()){
            ans.push_back(a);
            return ;
        }
        
        for(int j=0;j<nums.size();j++){
            if(m.find(nums[j])!=m.end()){
                continue;
            }
            a.push_back(nums[j]);
            m[nums[j]]=1;
            solve(nums,ans,a,m);
            a.pop_back();
            m.erase(nums[j]);
            
        }
        
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>a;
        map<int,int>m;
        solve(nums,ans,a,m);
        
        return ans;
    }
};