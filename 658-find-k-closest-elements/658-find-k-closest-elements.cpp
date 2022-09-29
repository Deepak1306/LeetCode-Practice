class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
         int n=arr.size();
        
        for(int i=0;i<n;i++){
            int y=abs(arr[i]-x);
            pq.push({y,arr[i]});
        }
        vector<int>ans;
        while(!pq.empty() && k){
            ans.push_back(pq.top().second);
            k--;
            pq.pop();
        }
        
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};