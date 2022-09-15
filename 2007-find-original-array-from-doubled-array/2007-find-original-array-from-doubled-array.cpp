class Solution {
public:
    vector<int> findOriginalArray(vector<int>& arr) {
        map<int,int>map;
        multiset<int>s;
        
        int n=arr.size();
        for(int i=0;i<n;i++){
            map[arr[i]]++;
            s.insert(arr[i]);
        }
        
        vector<int>ans;
        
        for(auto i:s){
            if(map.find(i)==map.end()){
                continue;
            }
            
            int half=i*2;
            map[i]--;
            if(map[i]==0){
                map.erase(i);
            }
            
            if(map.find(half)==map.end()){
                return {};
            }else{
            
                    ans.push_back(i);
                    map[half]--;
                    
                    if(map[half]==0){
                    map.erase(half);                        
                    }
                    
                }
            }
        

        return ans;  
    }
};