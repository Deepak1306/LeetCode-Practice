class Solution {
public:
    
    int findMax(vector<int>&count,char &c){
        int ans=INT_MIN;
        
        for(int i=0;i<26;i++){
            if(ans<count[i]){
                ans=count[i];
                c=i+'a';
            }
        }
        
        return ans;
    }
    
    string reorganizeString(string s) {
        vector<int>count(26,0);
        int n=s.length();
    
        for(int i=0;i<n;i++){
            count[s[i]-'a']++;
        }
        
        char c;
        int maxCount=findMax(count,c);
        
        if(maxCount>(n+1)/2){
            return "";
        }
        
        string str(n,'-');
        int i=0;
        
        while(count[c-'a']>0){
            str[i]=c;
            i+=2;
            count[c-'a']--;
        }
        
        
        for(int j=0;j<26;j++){
            
            while(count[j]>0){
                if(i>=n){
                    i=1;
                }
                str[i]=j+'a';
                i+=2;
                count[j]--;
                 
            }
        }
        
        return str;
        
    }
};