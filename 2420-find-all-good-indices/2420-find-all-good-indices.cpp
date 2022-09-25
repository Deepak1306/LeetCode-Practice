class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
          int n=nums.size();
          vector<int>left(n,0);
          vector<int>right(n,0);
        
        left[0]=1;
        right[n-1]=1;
        for(int i=1;i<n;i++){
            if(nums[i]<=nums[i-1]){
                left[i]=1+left[i-1];
            }
            else{
                left[i]=1;
            }
            
            if(nums[n-1-i]<=nums[n-i]){
                right[n-1-i]=1+right[n-i];
            }else{
                right[n-i-1]=1;
            }
            
        }
        
        vector<int>ans;
        
        for(int i=k;i<n-k;i++){
            if(left[i-1]>=k && right[i+1]>=k){
                ans.push_back(i);
            }
        }
        return ans;
         
    }
}; 