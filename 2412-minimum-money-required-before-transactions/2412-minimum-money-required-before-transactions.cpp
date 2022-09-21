class Solution {
public:
    
    static bool comp(vector<int> &a, vector<int> &b){
        return a[1]<b[1];
    }
    
    long long minimumMoney(vector<vector<int>>& arr) {
        
        long long ans=INT_MAX;
        long long sum=0;
        int n=arr.size();
        sort(arr.begin(),arr.end(),comp);
        
        for(auto i:arr){
            sum-=i[0];
            ans=min(sum,ans);
            sum+=min(i[0],i[1]);
        }
        
        return -1*ans;
    }
};