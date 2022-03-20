class Solution {
public:
    string reverseWords(string s) {
        
        int n=s.length();
        
        string str;
        string ans;
        for(int i=0;i<n;i++){
            
            if(s[i]==' '){
                if(str.length()==0){
                    continue;
                }
                
                ans=str+' '+ans;
                str="";
            }
            else{
                
                str+=s[i];
            }
            
                        
        }
        
        if(str.length()!=0){
          ans=str+' '+ans;    
        }
        
        ans.pop_back();
        
        
        return ans;
    }
};