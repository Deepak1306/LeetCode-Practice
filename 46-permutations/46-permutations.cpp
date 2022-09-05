class Solution {
public:
    
    void solve(vector<int>&nums,int n,vector<vector<int>>&ans,vector<int>a){
        if(a.size()==n){
            ans.push_back(a);
            return ;
        }
        
        for(int i=0;i<n;i++){
            if(nums[i]==-11){
                continue;
            }
            int c=nums[i];
            nums[i]=-11;
            a.push_back(c);
            solve(nums,n,ans,a);
            a.pop_back();
            nums[i]=c;
        }
        
        
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        
        vector<int>a;
        solve(nums,n,ans,a);
        
        return ans;
        
    }
};