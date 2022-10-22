class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int>mp;
        map<char,int>mp1;
        
        int n=s.length();
        
        for(int k=0;k<t.length();k++){
            mp[t[k]]++;
            mp1[t[k]]++;
        }
        
        int i=0;
        int j=0;
        
        int x=1e5;
        int y=2e5;
        
        int count=0;
        
        while(i<n){
            
            if(mp.find(s[i])!=mp.end()){
                
                if(mp1[s[i]]>0){
                    count++;
                }
                
                mp1[s[i]]--;
                
            }
            
            while(count==t.length()){
                
                if(y-x+1>i-j+1){
                    y=i;
                    x=j;     
                }
                
                if(mp.find(s[j])!=mp.end()){
                    
                    if(mp1[s[j]]>=0){
                      count--;  
                    }
                    mp1[s[j]]++;
                }
                
                j++;
            }
            
           i++;
            
        }
        if(x==1e5){
            return "";
        }
        
        return s.substr(x,y-x+1);
        
    }
};