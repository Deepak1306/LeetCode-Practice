class Solution {
public:
    string reformatDate(string s) {
        int n=s.length();
        
        map<string,string>m;
        m["Jan"]="01";
        m["Feb"]="02";
        m["Mar"]="03";
        m["Apr"]="04";
        m["May"]="05";
        m["Jun"]="06";
        m["Jul"]="07";
        m["Aug"]="08";
        m["Sep"]="09";
        m["Oct"]="10";
        m["Nov"]="11";
        m["Dec"]="12";
        
        string ans="";
        for(int i=n-1;i>=n-4;i--){
            ans=s[i]+ans;
        }
        ans+='-';
        
        int i=0;
        string s1="";
        while(i<=1){
            if(s[i]>'9' || s[i]<'0'){
                break;
            }
            s1+=s[i];
            i++;
        }
        
        ans+=m[s.substr(i+3,3)];
        ans+='-';
        
        if(s1.length()==1){
            s1=to_string(0)+s1;
        }
        
        ans+=s1;
        
        return ans;
        
    }
};