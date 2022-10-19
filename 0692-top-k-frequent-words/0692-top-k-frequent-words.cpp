class Solution {
public:
    
    static bool comp(pair<int,string>a,pair<int,string>b){
        if(a.first==b.first){
            return a.second<b.second;
        }
        return a.first>b.first;
        
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>mp;
        
        int n=words.size();
        
        for(int i=0;i<n;i++){
           mp[words[i]]++;    
        }
        
        vector<pair<int,string>>v;
        
        for(auto it:mp){
           v.push_back({it.second,it.first});    
        }
        
        sort(v.begin(),v.end(),comp);
        vector<string>ans;
        
        for(int i=0;i<k;i++){
            ans.push_back(v[i].second);
        }
        
        return ans;
        
        
    }
};