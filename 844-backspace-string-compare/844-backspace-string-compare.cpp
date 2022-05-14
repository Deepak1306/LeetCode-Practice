class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        int i=0;
        while(i<s.length()){
            if(s[i]=='#'){
                if(i-1<0){
                    s.erase(i,1);
                    continue;
                }
                s.erase(i-1,1);
                s.erase(i-1,1);
                
                i--;
            }
            else{
                i++;
            }
        }
        
        int j=0;
         while(j<t.length()){
            if(t[j]=='#'){
                if(j-1<0){
                    t.erase(j,1);
                    continue;
                }
                t.erase(j-1,1);
                t.erase(j-1,1);
                
                j--;
            }
            else{
                j++;
            }
        }
        
        
        if(s==t){
            return true;
        }
        
        return false;
    }
};