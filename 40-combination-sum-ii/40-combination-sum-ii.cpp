class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>& arr, int k, vector<int> a,int i){
        if(k==0){
            ans.push_back(a);
            return ;
        }
        else if(i==arr.size() || k<0){
            return ;
        }
        int j=i;
        
        while(j<arr.size()){
            if(j==i || arr[j]!=arr[j-1]){
                a.push_back(arr[j]);
                solve(arr,k-arr[j],a,j+1);
                a.pop_back();
            }
            j++;
        }
        
        
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<int>a;
        
       sort(candidates.begin(),candidates.end());
             int i=0;
        solve(candidates,target,a,i);
        return ans;
    }
};