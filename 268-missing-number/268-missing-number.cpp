class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        
        for(int i=0;i<=n;i++){
            if(m[i]==0){
                ans=i;
                break;
            }
        }
        
        return ans;
        
    }
    
};