class Solution {
public:
    bool validPalindrome(string s) {
      int n=s.size();
        
        if(n==1){
            return true;
        }
        
        int i=0;
        int j=n-1;
        
        int i1=i;
        int j1=j;
        
        int count1=0;
       
        
        
        if(s[i]!=s[j]){
            count1++;
            i1++;
            
        }
        
        while(i1<j1){
            if(s[i1]!=s[j1]){
                count1++;
                i1++;
                continue;
            }
            
            i1++;
            j1--;
        }
        int count2=0;
        
        if(s[i]!=s[j]){
            count2++;
            j--;
        }
        
         while(i<j){
            if(s[i]!=s[j]){
                count2++;
                j--;
                continue;
            }
            
            i++;
            j--;
        }
        if(count1>1 && count2>1){
            return false;
        }
        
        return true;
        
    }
};