class Solution {
public:
   
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        
        for(int i=1;i<intervals.size();i++){
            int k=ans.size()-1;
            
            if(ans[k][1]>=intervals[i][0] && ans[k][1]<=intervals[i][1]){
                ans[k][1]=intervals[i][1];
            }else if(ans[k][1]>intervals[i][1]){
                continue;
            }
            else{
                ans.push_back({intervals[i][0],intervals[i][1]});
            }
            
        }
        
        return ans;
        
    }
};