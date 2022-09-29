class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
         priority_queue<pair<int,int>>pq;
        
         int n=arr.size();
        
        for(int i=0;i<k;i++){
            int y=abs(arr[i]-x);
            pq.push({y,arr[i]});
        }
        
        for(int i=k;i<n;i++){
             int y=abs(arr[i]-x);
            
            if(y<pq.top().first){
                pq.pop();
                pq.push({y,arr[i]});                
            }
        }
        
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};