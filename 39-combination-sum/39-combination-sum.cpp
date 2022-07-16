class Solution {
public:
    void solve(vector<int>& arr, int k,vector<vector<int>>& ans, vector<int>a,int i){
        if(k==0){
           ans.push_back(a);
            return ;
        }
        else if(i==arr.size() || k<0){
            return ;
        }
        
        solve(arr,k,ans,a,i+1);
        a.push_back(arr[i]);
        solve(arr,k-arr[i],ans,a,i);
        a.pop_back();
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>a;
        solve(candidates,target,ans,a,0);
        
        return ans;
    }
};