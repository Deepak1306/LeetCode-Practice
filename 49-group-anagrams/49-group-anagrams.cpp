class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int>m;
        
        int k=1;
        
        vector<vector<string>>v;
        for(int i=0;i<strs.size();i++){
            string s=strs[i];
            sort(s.begin(),s.end());
            
            if(m.find(s)!=m.end()){
                v[m[s]-1].push_back(strs[i]);
            }else{
                v.push_back({strs[i]});
                m[s]=k;
                k++;
            }
        }
        return v;
        
        
    }
};