class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.length();
        int m=needle.length();
        
        if(m==0){
            return 0;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                string s=haystack.substr(j,i-j+1);
                if(s==needle){
                    return j;
                }
            }
        }
        
        return -1;
    }
};