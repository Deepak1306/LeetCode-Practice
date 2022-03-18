class Solution {
public:
    int trap(vector<int>& height) {
        
        int n=height.size();
        
        int *lMax=new int[n];
        lMax[0]=height[0];
        
        for(int i=1;i<n;i++){
            lMax[i]=max(height[i],lMax[i-1]);
        }
        
        int *rMax=new int[n];
        rMax[n-1]=height[n-1];
        
        for(int i=n-2;i>=0;i--){
            rMax[i]=max(rMax[i+1],height[i]);
        }
        
        
        int store=0;
        
        for(int i=0;i<n;i++){
            store+=min(lMax[i],rMax[i])-height[i];
        }
        
        return store;
        
        
    }
};