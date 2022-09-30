class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> walls, ans;                
        for (auto b : buildings) {
           
            walls.push_back({b[0], -b[2]});
            walls.push_back({b[1], b[2]});
        }
        sort(walls.begin(), walls.end());                
        
        multiset<int> leftWallHeights = {0};        
        int top = 0;                                        
        for (auto w : walls) {
            if (w[1] < 0) {                           
                leftWallHeights.insert(-w[1]);
            } else {                                        
                leftWallHeights.erase(leftWallHeights.find(w[1]));
            }
            
            if (*leftWallHeights.rbegin() != top) {        
                ans.push_back({w[0], top = *leftWallHeights.rbegin()});
            }
        }
        
        return ans;
    }
};