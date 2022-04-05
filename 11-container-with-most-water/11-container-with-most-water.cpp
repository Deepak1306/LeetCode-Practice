class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n=height.size();
        
        int i=0;
        int j=n-1;
        
        int ans=INT_MIN;
        
       while(i<j){
           int a=min(height[i],height[j]);
           int b=j-i;
           
           ans=max(ans,a*b);
           
           if(height[i]==min(height[i],height[j])){
               i++;
           }else{
               j--;
           }
           
           
       }
        
        return ans;
    }
};