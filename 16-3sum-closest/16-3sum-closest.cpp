class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        long ans=INT_MAX;
        int sum=0;
        for(int k=0;k<n-2;k++){
            int i=k+1;
            int j=n-1;
            
            while(i<j){
                sum=nums[i]+nums[j]+nums[k];
                
                // cout<<sum<<" "<<ans<<endl;
                
                if(sum<target){
                    if(abs(sum-target)<abs(ans-target)){
                        ans=sum;
                    }
                    i++;
                }else if(sum>target){
                    if(abs(sum-target)<abs(ans-target)){
                        ans=sum;
                    }
                    j--;
                }else{
                    return sum;
                }   
            }
            
        }
        
        return ans;
    }   
};