class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        
        if(nums.size()<4){
            return ans;
        }
        
        set<vector<int>>st;
        
        sort(nums.begin(),nums.end());
        long long int sum=0;
        
        for(int i=0;i<nums.size()-3;i++){
            for(int j=i+1;j<nums.size()-2;j++){
                
                sum=(long long int)target-(long long int)nums[j]-(long long int)nums[i];
                
                int k=j+1;
                int r=nums.size()-1;
                
                
                while(k<r){
                    int a=nums[k]+nums[r];
                    
                    if(a>sum){
                        r--;
                    }else if(a<sum){
                        k++;
                    }else{
                        st.insert({nums[i],nums[j],nums[k],nums[r]});
                        k++;
                        r--;
                    }
                }
                
            }
        }
        
        for(auto s:st){
            ans.push_back(s);
        }
        
        
        return ans;
    }
};