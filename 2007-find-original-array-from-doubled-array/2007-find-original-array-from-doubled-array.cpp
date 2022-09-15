class Solution {
public:
    vector<int> findOriginalArray(vector<int>& arr) {
        map<int,int>map;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        for(int i=0;i<n;i++){
            map[arr[i]]++;
        }
        
        vector<int>ans;
        
        for(int i=0;i<n;i++){
            if(map.find(arr[i])==map.end()){
                continue;
            }
            
            int half=arr[i]*2;
            map[arr[i]]--;
            if(map[arr[i]]==0){
                map.erase(arr[i]);
            }
            
            
            if(map.find(half)==map.end()){
                return {};
            }else{
            
                    ans.push_back(arr[i]);
                    map[half]--;
                    
                    if(map[half]==0){
                    map.erase(half);                        
                    }
                    
                }
            }
        
        
        return ans;  
    }
};