class Solution {
public:
    int largestPerimeter(vector<int>& arr) {
        
        sort(arr.begin(),arr.end());
        int n=arr.size();
        
        int ans=0;
        
        for(int k=n-1;k>=2;k--){
            int i=k-2;
            int j=k-1;
            
            if(arr[i]+arr[j]>arr[k]){
                ans=max(ans,arr[i]+arr[j]+arr[k]);
            }
            
        }
        
        return ans;
        
    }
};