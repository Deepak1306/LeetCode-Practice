class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=t.length();
        int k=0;
        
        for(int i=0;i<n;i++){
            if(k==s.length()){
                return true;
            }
            
            if(s[k]==t[i]){
                k++;
            }
        }
        
        if(k==s.length()){
            return true;
        }
        
        return false;
    }
};