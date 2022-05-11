class Solution {
public:
    bool isIsomorphic(string s, string t) {
      int n=s.length();
       int m=t.length();
        
        
        if(n!=m){
            return false;
        }
        
        unordered_map<char,char>m1;
        unordered_map<char,char>m2;
        
        for(int i=0;i<n;i++){
            if(!m1[s[i]] && !m2[t[i]]){
                m1[s[i]]=t[i];
                m2[t[i]]=s[i];
                
            }else if(m1[s[i]]!=t[i] || m2[t[i]]!=s[i]){
                return false;
            }
            
            
        }
        
        return true;
        
    }
};