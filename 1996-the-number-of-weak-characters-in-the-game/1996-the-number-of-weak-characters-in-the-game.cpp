class Solution {
public:    
    int numberOfWeakCharacters(vector<vector<int>>& arr) {
        
        map<int,multiset<int>>m;
        int n=arr.size();
        for(int i=0;i<n;i++){
            m[arr[i][0]].insert(arr[i][1]);
        }
        
        
        vector<pair<int,multiset<int>>>v(m.begin(),m.end());
        
        sort(v.begin(),v.end(),greater<pair<int,multiset<int>>>());
        
        int mx=0;
        for(auto it:v[0].second){
            mx=max(mx,it);
        }
        // cout<<mx<<" ";
        
        int count=0;
        for(int i=1;i<v.size();i++){
            
            for(auto it:v[i].second){
                if(it>=mx){
                    mx=it;
                    continue;
                }else{
                    count++;
                }
                
                // cout<<mx<<" ";
            }
        }
        
        return count;
    }
};