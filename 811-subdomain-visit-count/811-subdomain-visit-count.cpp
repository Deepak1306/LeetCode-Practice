class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
       map<string,int>map;
        int n=cpdomains.size();
        
        for(int i=0;i<n;i++){
            int m=cpdomains[i].length();
            
            int nums=0;
            for(int j=0;j<m;j++){
                if(cpdomains[i][j]==' '){
                    break;
                }
                
                nums=nums*10+(cpdomains[i][j]-'0');
            }
            
            string s="";
            for(int j=m-1;j>=0;j--){
                if(cpdomains[i][j]==' '){
                    break;
                }
                
                if(cpdomains[i][j]=='.'){
                    map[s]+=nums;
                }
                
                s=cpdomains[i][j]+s;
            }
            
            map[s]+=nums;
        }
        
        vector<string>ans;
        for(auto it:map){
            string str=to_string(it.second);
            ans.push_back(str+" "+it.first);
        }
        
        return ans;
        
    }
};