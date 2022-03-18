class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
       
        vector<vector<int>>ans;
        
        if(n<3){
            return ans;
        }
        
       set<vector<int>>seen;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n-1;i++){
           int count= 0-nums[i];
            
            int j=i+1;
            int k=n-1;
            
            
            
            while(j<k){
                if(nums[j]+nums[k]<count){
                    j++;
                }else if(nums[j]+nums[k]>count){
                    k--;
                }else{
                    
                    if(nums[j]==nums[k]){
                      seen.insert({nums[i],nums[j],nums[k]});
                        break;
                    }else{
                        
                        seen.insert({nums[i],nums[j],nums[k]});
                        
                        int j1=j+1;
                        int k1=k-1;
                        
                        while(j1<=k1 && nums[j1]==nums[j]){
                            j1++;
                        }
                        while(k1>=j1 && nums[k1]==nums[k]){
                            k1--;
                        }
                        
                        j=j1;
                        k=k1;
                        
                        
                    }
                    
                 }
            }  
            
        }
        for(auto i:seen){
          ans.push_back(i);    
        }
        
        return ans;
        
                        
    }
};