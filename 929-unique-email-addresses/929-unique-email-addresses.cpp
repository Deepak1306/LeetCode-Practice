class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string>s;
        
        int i=0;
        int n=emails.size();
        
        for(int i=0;i<n;i++){
            string str;
            
            string st=emails[i];
            
            int j=0;
            bool domain=false;
            while(j<st.length()){
                if(st[j]=='.' && domain){
                    str+=st[j];
                }else if(st[j]=='.'){
                    j++;
                    continue;
                }
                
                if(st[j]=='+' && !domain){
                    while(st[j]!='@'){
                        j++;
                    }
                }
                if(st[j]=='@'){
                    domain=true;
                }
                str+=st[j];
                j++;
                    
            }
            
            s.insert(str);
            
            
            
            
        }
        
        return s.size();
        
    }
};