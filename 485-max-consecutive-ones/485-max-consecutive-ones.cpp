class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int i=0;
        int j=0;
        
        int ans=0;
        
        int count=0;
        while(i<nums.size()){
            if(nums[i]==0){
                count++;
            }
            
            while(count>0){
                if(nums[j]==0){
                    count--;
                }
                
                j++;
            }
            
            ans=max(ans,i-j+1);
            i++;
            
        }
        
        return ans;
    }
};