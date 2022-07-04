class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      int n=heights.size();
        
        stack<int>s;
        int left[n];
        left[0]=-1;
        s.push(0);
        for(int i=1;i<n;i++){
            while(!s.empty() && heights[i]<=heights[s.top()]){
                s.pop();
            }
            
            if(s.empty()){
                left[i]=-1;
            }else{
                left[i]=s.top();
            }
            
            s.push(i);
        }
        
        while(!s.empty()){
            s.pop();
        }
        
        int right[n];
        right[n-1]=n;
        
        s.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!s.empty() && heights[i]<=heights[s.top()]){
                s.pop();
            }
            
            if(s.empty()){
                right[i]=n;
            }else{
                right[i]=s.top();
            }
            
            s.push(i);
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            ans=max(ans,(right[i]-left[i]-1)*heights[i]);
        }
        
        
        return ans;
    }
};