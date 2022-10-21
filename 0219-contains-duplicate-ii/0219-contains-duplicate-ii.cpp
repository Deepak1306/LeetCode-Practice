class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& arr, int k) {
        int n=arr.size();
        map<int,int>mp;
        mp[arr[n-1]]=n-1;
        for(int i=n-2;i>=0;i--){
            if(mp.find(arr[i])!=mp.end() && mp[arr[i]]<=i+k){
                  return true;
            }
            mp[arr[i]]=i;
        }
        
        return false;
        
    }
};