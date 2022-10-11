class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>mi(n);
        vector<int>ma(n);
        
        mi[0]=nums[0];
        ma[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            mi[i]=min(mi[i-1],nums[i]);
            ma[n-i-1]=max(ma[n-i],nums[n-i-1]);
        }
        
        for(int i=1;i<n-1;i++){
            if(nums[i]>mi[i-1] && nums[i]<ma[i+1]){
                return true;
            }
        }
        
        return false;
        
    }
};