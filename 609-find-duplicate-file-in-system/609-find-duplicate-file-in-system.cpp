class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        int n=paths.size();
        map<string,vector<string>>mp;
        vector<vector<string>>ans;
        
        for(int i=0;i<n;i++){
            string str="";
            string s="";
            string s1="";
            bool flag=false;
            
            int j=0;
            while(j<paths[i].length()){
                if(paths[i][j]==' '){
                    break;
                }
                str+=paths[i][j];
                j++;
            }
            
            str+='/';
            
            j++;
            while(j<paths[i].length()){
               if(paths[i][j]==' '){
                    mp[s].push_back(str+s1);    
                   s1="";
                   s="";
               }else if(paths[i][j]=='('){
                   flag=true;
                   
               }
               else if(paths[i][j]==')'){
                   j++; 
                   flag=false;
                   continue;
               }  
               else if(flag){
                    s+=paths[i][j]; 
               }  
               else{
                    s1+=paths[i][j];
               }
                
                j++;
                
            }
            mp[s].push_back(str+s1);  
        }
        
        for(auto it:mp){
           if(it.second.size()<2){
               continue;
           }
            ans.push_back(it.second);
        }
        
        return ans;
        
    }
};