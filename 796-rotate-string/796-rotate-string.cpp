class Solution {
public:
    bool rotateString(string s, string goal) {
        
        int i=0;
        int n=s.length();
        
        if(s==goal){
            return true;
        }
        
        while(i<n){
            
            char temp=s[0];
            for(int i=0;i<n-1;i++){
                s[i]=s[i+1];
            }
            s[n-1]=temp;
            
            if(s==goal){
                return true;
            }
            
            i++;
            
        }
        
        return false;
        
    }
};