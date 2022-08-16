class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n=s.length();
        
        int i=0;
        int j=0;
        int ans=0;
        map<char,int>m;
        
        while(i<n){
            if(m.find(s[i])!=m.end()){
                j=max(j,m[s[i]]+1);
            }
            
            ans=max(ans,i-j+1);
            m[s[i]]=i;
            i++;
            
        }
        
        return ans;
        
    }
};