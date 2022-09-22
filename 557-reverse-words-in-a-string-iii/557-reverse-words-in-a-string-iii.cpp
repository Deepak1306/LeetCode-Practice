class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        
        int i=0;
        
        string str="";
        string s1="";
        while(i<n){
            if(s[i]==' '){
                str=str+s1+' ';
                s1="";
            }
            else{
                s1=s[i]+s1;
            }
            
            i++;
        }
        str=str+s1;
        return str;
    }
};