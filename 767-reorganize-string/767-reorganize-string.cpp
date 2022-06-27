class Solution {
public:
    char maxChar(string s, vector<int>count){
        char ch;
        int c=0;
        
        for(int i=0;i<count.size();i++){
            if(c<count[i]){
                c=count[i];
                ch=i+'a';
            }
        }
        
        return ch;
    }
    
    
    string reorganizeString(string s) {
       vector<int>count(26,0);
        
        int n=s.length();
        if(n==0 || n==1){
            return s;
        }
        
        
        for(int i=0;i<n;i++){
           int c=s[i]-'a';
            count[c]++;
        }
        
        char ch=maxChar(s,count);
        int maxCount=count[ch-'a'];
        
        if(maxCount>(n+1)/2){
            return "";
        }
        
        string ans(n,' ');
        
        int in=0;
        while(maxCount>0){
            ans[in]=ch;
            in+=2;
            maxCount--;
        }
        
        count[ch-'a']=0;
        
        for(int i=0;i<count.size();i++){
            
            while(count[i]>0){
             
            in=(in>=n)?1:in;
            ans[in]=i+'a';
            count[i]--;
            in+=2;  
            }
        }
        
        return ans;
        
        
    }
};