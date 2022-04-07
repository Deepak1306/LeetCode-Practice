class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        
        
        while(stones.size()>1){
            sort(stones.begin(),stones.end());
            
            int n=stones.size();
            
            int a=stones[n-1];
            int b=stones[n-2];
            
            stones.pop_back();
            stones.pop_back();
            
            stones.push_back(a-b);
            
            
        }
        
        return stones[0];
        
    }
};