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
            m1[s[i]]=t[i];
            m2[t[i]]=s[i];
        }
        
        for(int j=0;j<m;j++){
            if(m1[s[j]]!=t[j] || m2[t[j]]!=s[j]){
                return false;
            }
        }
        
        return true;
        
    }
};