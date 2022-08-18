class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int>m;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        
        vector<int>ans;
        
        for(auto i:m){
            if(i.second>n/3){
                ans.push_back(i.first);
            }
        }
        
        return ans;
    }
};