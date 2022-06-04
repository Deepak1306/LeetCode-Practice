class Solution {
public:
    int thirdMax(vector<int>& nums) {
     sort(nums.begin(),nums.end());
        int n=nums.size();
       
        int i=1;
        int m=nums[n-1];
        
       
        int k=n-2;
        
        while(i<=2 && k>=0){
            if(nums[k]<m){
                i++;
                m=nums[k];
            }
            k--;
        }
        if(i<=2){
            return nums[n-1];
        }
        
        return m;
    }
};