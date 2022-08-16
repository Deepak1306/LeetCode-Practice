class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n=s.length();
        
        int i=0;
        int j=0;
        int ans=0;
        map<char,int>m;
        
        while(i<n){
            m[s[i]]++;
            
            while(m[s[i]]>1){
                m[s[j]]--;
                j++;
                
            }
            
            ans=max(ans,i-j+1);
            i++;
        }
        
        return ans;
        
    }
};