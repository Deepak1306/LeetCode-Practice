class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        int n=s.length();
        
        unordered_map<char,int>map;
        
        for(int i=0;i<s.length();i++){
            map[s[i]]=i;
        }
        
        set<char>ch;
        vector<int>ans;
        int val=0;
        
        
        for(int i=0;i<s.length();i++){
           
            ch.insert(s[i]);
            
            if(i==map[s[i]]){
                ch.erase(s[i]);
            }
            
            if(ch.empty()){
                ans.push_back(i+1-val);
                val=i+1;
            }
        
            
        }
        
       
        
        return ans;
        
        
        
    }
};