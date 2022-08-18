class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            if(arr[nums[i]]==-1){
                return nums[i];
            }else{
                arr[nums[i]]=-1;
            }
        }
        
        return -1;
        
    }
};