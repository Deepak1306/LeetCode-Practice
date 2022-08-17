class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int count=1;
        int i=1;
        map<int,int>m;
        m[nums[0]]=1;
        
        for(int k=1;k<nums.size();k++){
            if(m.find(nums[k])!=m.end()){
                continue;
            }
            else{
                nums[i]=nums[k];
                count++;
                i++;
                
                m[nums[k]]=1;
            }
        }
        
        return count;
    }
};