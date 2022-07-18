class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        
        int i=0;
        int n=strs.size();
        
        string s1=strs[0];
        string s2=strs[n-1];
        
        int k=0;
        int j=0;
        
        string ans="";
        while(k<s1.length() && j<s2.length()){
            if(s1[k]!=s2[j]){
                break;
            }
            
            ans+=s1[k];
            k++;
            j++;
        }
        return ans;
    }
};