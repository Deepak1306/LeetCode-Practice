class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int m=queries.size();
         
        map<int,int>map;
        
        int sum=0;
        
        vector<int>ans;
        
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                sum+=nums[i];
                map[i]=1;
            }
        }
        
        for(int i=0;i<m;i++){
            
            int x=nums[queries[i][1]]+queries[i][0];
            if(x<0){
                x=-1*x;
            }
            
            if(x%2==0){
                
                if(map.find(queries[i][1])!=map.end()){
                    sum+=queries[i][0];
                }else{
                    sum+=nums[queries[i][1]]+queries[i][0];
                    map[queries[i][1]]=1;
                }
            }
            else if(map.find(queries[i][1])!=map.end()){
                    sum-=nums[queries[i][1]];
                    map.erase(queries[i][1]);
            }
            
            nums[queries[i][1]]=nums[queries[i][1]]+queries[i][0];
            ans.push_back(sum);
        }
        
        return ans;
        
    }
};