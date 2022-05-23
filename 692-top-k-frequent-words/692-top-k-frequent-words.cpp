bool comp(pair<string,int>a,pair<string,int>b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    
    return a.second>b.second;
}

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        
        unordered_map<string,int>m;
        
        for(int i=0;i<words.size();i++){
            m[words[i]]++;
        }
        
        vector<pair<string,int>>v(m.begin(),m.end());
        
        sort(v.begin(),v.end(),comp);
        
        vector<string>ans;
        for(int i=0;i<k;i++){
            ans.push_back(v[i].first);
        }
        
        return ans;
        
        
    }
};