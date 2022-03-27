class Solution {
public:
    static bool comp(pair<int,int>a1,pair<int,int>a2){
        if(a1.first==a2.first){
            return a1.second<a2.second;
        }
        return a1.first<a2.first;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        vector<pair<int,int>>p(0);
        
        
        for(int i=0;i<n;i++){
         auto a = accumulate(mat[i].begin(), mat[i].end(), 0);
         p.push_back({a, i});   
        }
            
        sort(p.begin(),p.end(),comp);
        
        vector<int>ans;
        
        for(int i=0;i<k;i++){
            ans.push_back(p[i].second);
        }
        
        return ans;
        
    }
};