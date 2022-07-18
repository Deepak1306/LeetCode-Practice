class Solution {
public:
    string reverseWords(string s) {
       
        int n=s.length();
        string str="";
        string st="";
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                if(st==""){
                    continue;
                }
                str=st+' '+str;
                st="";
            }else{
                st+=s[i];
            }
        }
        if(st!=""){
        str=st+' '+str;            
        }
        str.pop_back();
        return str;
    }
};