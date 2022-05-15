class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>& candidates, int target,int in, int n, vector<int>& temp){
      if(target==0){
          ans.push_back(temp);
          return;
      }  
      if(in==n){
          return;
      }
     if(target<0){
        return;
     }
       temp.push_back(candidates[in]);
        helper(candidates,target-candidates[in],in,n,temp);
        temp.pop_back();
       
        helper(candidates,target,in+1,n,temp);
        
        
        return ;
        
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int>temp;
        int n=candidates.size();
        
        helper(candidates,target,0,n,temp);
        return ans;
        
    }
};