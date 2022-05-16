class Solution {
public:
    int majorityElement(vector<int>& nums) {
      unordered_map<int,int>m;
      set<int>s;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
          s.insert(nums[i]);
          m[nums[i]]++;  
        }
        
        int ans=0;
        
        for(auto a:s){
            if(m[a]>n/2){
                ans=a;
                break;
            }
        }
        return ans;
    }
};