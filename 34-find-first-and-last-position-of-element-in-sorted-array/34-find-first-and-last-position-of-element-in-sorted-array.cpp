class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int>in;
        vector<int>ans;
        
        for(int i=0;i<nums.size();i++){
           
            if(nums[i]==target){
                in.push_back(i);
            }
              
        }
        
        if(in.size()==0){
            ans.push_back(-1);
            ans.push_back(-1);
            
            return ans;
        }else if(in.size()==1){
            in.push_back(in[0]);
            return in;
            
        }else{
            ans.push_back(in[0]);
            ans.push_back(in[in.size()-1]);
            return ans;
        }
        
        
    }
};