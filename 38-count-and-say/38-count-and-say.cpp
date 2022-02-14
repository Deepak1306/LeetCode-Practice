class Solution {
public:
    
    string helper(string s){
        string str="";
        int n=s.length();
        int count=1;
        
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                count++;
            }else{
                str+=char(count+'0');
                str+=s[i-1];
                count=1;
            }
        }
        
        
            str+=char(count+'0');
            str+=s[n-1];
        
        return str;
    }
    
    string countAndSay(int n) {
      if(n==1){
          return "1";
      }
        
       string s=countAndSay(n-1);
        
        return helper(s);
        
        
    }
};