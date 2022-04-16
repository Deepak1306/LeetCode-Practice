class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
       
        int n=nums.size();
        
        unordered_map<int,int>m;
        
        
        for(int j=0;j<n;j++){
           m[nums[j]]++;    
        }
        
        
        
        vector<int>ans;
        for(int i=1;i<=n;i++){
          if(m.find(i)==m.end()){
              ans.push_back(i);
          }  
            
        }
        
        return ans;
        
        
    }
};