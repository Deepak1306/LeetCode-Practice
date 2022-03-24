class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        
        if(n==1){
            return intervals;
        }
        
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        
        
        
        for(int i=1;i<n;i++){
            int k=ans.size()-1;
            
            if(intervals[i][0]<=ans[k][1] && intervals[i][1]<=ans[k][1]){
                continue;
            }else if(intervals[i][0]<=ans[k][1] && intervals[i][1]>ans[k][1]){
                ans[k][1]=intervals[i][1];
            }else{
                ans.push_back(intervals[i]);
            }
             
        }
        
        return ans;
        
    }
};