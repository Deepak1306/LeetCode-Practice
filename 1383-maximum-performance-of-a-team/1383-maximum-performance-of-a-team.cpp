class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        if(k==0){
            return 0;
        }
        
        int mod=1e9+7;
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({efficiency[i],speed[i]});
        }
        
        
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        priority_queue<int,vector<int>,greater<int>>pq;
        
        long sum=0;
        long ans=INT_MIN;
        for(int i=0;i<k-1;i++){
            pq.push(v[i].second);
            sum=(sum + v[i].second);
            ans=max(ans,(sum*v[i].first));
        }
        ans=ans;
        
        for(int i=k-1;i<n;i++){
            ans=max(ans,v[i].first*(sum+v[i].second));
            
            if(!pq.empty() && v[i].second>pq.top()){
                
                sum-=pq.top();
                sum=sum + v[i].second;
                pq.pop();
                pq.push(v[i].second);
                 ans=max(ans,sum*v[i].first);
                
            }
        }
        
        return ans%mod;
        
        
        
    }
};