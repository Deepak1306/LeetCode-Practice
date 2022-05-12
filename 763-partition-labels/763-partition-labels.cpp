class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.length();
        unordered_map<char,int>m;
        
        for(int i=0;i<n;i++){
            m[s[i]]=i;
        }
        
        set<char>se;
        vector<int>ans;
        int k=0;
        
        for(int i=0;i<n;i++){
          se.insert(s[i]);
            
            if(i==m[s[i]]){
                se.erase(s[i]);
            }
            if(se.empty()){
                ans.push_back(i-k+1);
                k=i+1;
            }
            
        }
        return ans;
    }
};