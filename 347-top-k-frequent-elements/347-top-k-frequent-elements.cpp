class Solution {
public:
    static bool comp(pair<int,int>a1,pair<int,int>a2){
        return a1.second>a2.second;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        
        vector<pair<int,int>>smallAns(map.begin(),map.end());
        
        sort(smallAns.begin(),smallAns.end(),comp);
        
        vector<int>ans;
        
        for(int i=0;k>0;i++){
            ans.push_back(smallAns[i].first);
            k--;
        }
        
        return ans;
    }
};