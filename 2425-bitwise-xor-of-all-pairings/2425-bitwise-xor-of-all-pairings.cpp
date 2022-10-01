class Solution {
public:
    int xorAllNums(vector<int>& a, vector<int>& b) {
        int n=a.size();
        int m=b.size();
        
        int i=0;
        if(n%2==0 && m%2==0){
            return 0;
        }else if(n%2==0){
            for(auto it:a){
                i^=it;
            }
            return i;
        }else if(m%2==0){
            for(auto it:b){
                i^=it;
            }
            
            return i;
        }
        
        for(auto it:a){
            i^=it;
        }
        
        for(auto it:b){
            i^=it;
        }
        
        return i;
        
        
    }
};