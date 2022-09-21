class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0;
        
        map<int,int>map;
        
        while(i<n){
            if(map.find(target-nums[i])!=map.end()){
                return {map[target-nums[i]],i};
            }
            map[nums[i]]=i;
            i++;
        }
        
        return {-1,-1};
        
        
    }
};