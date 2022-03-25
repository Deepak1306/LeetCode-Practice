class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int n=costs.size();
        
        int count=0;
        
        vector<int>diff;
        
        for(int i=0;i<n;i++){
            count+= costs[i][0];
            diff.push_back(costs[i][1]-costs[i][0]);
        }
        
        sort(diff.begin(),diff.end());
        
        
        for(int i=0;i<n/2;i++){
            count+=diff[i];
        }
        
        return count;
        
    }
};