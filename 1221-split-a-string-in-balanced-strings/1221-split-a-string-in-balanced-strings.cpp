class Solution {
public:
    int balancedStringSplit(string s) {
        int cL=0;
        int cR=0;
        
        int count=0;
        
        for(int i=0;i<s.length();i++){
            
            if(s[i]=='L'){
                cL++;
            }else{
                cR++;
            }
            
            if(cL==cR && cL!=0){
                count++;
                cL=0;
                cR=0;
            }
        }
        
        return count;
    }
};