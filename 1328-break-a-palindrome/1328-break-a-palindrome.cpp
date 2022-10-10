class Solution {
public:
    
    bool palin(string s){
        int i=0;
        int j=s.length()-1;
        
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
    
    string breakPalindrome(string s) {
        bool check=false;
        int n=s.length();
        
        if(n==1){
            return "";
        }
        
        for(int i=0;i<n;i++){
            if(s[i]!='a'){
                char c=s[i];
                s[i]='a';
                
                if(!palin(s)){
                    check=true;
                    break;
                }
                
                s[i]=c;
            }
        }
        
        if(check==true){
            return s;
        }
        s[n-1]='b';
        return s;
    }
};