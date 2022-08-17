class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        
        int left[n];
        left[0]=height[0];
        
        for(int i=1;i<n;i++){
            left[i]=max(height[i],left[i-1]);
        }
        
        int right[n];
        right[n-1]=height[n-1];
        
        for(int j=n-2;j>=0;j--){
            right[j]=max(height[j],right[j+1]);
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            ans+=min(left[i],right[i])-height[i];
        }
        
        return ans;
        
    }
};