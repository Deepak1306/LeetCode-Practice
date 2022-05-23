class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int  n=heights.size();
        
        stack<int>st;
        int lb[n];
        lb[0]=-1;
        st.push(0);
        for(int i=1;i<n;i++){
            
            while(st.size()>0 && heights[i]<=heights[st.top()]){
                st.pop();
            }
            
            if(st.size()==0){
                lb[i]=-1;
            }else{
                lb[i]=st.top();
                
            }
            
            st.push(i);
        }
        
        while(st.size()>0){
            st.pop();
        }
        
        int rb[n];
        rb[n-1]=n;
        st.push(n-1);
        
        
        for(int i=n-2;i>=0;i--){
            
            while(st.size()>0 && heights[i]<=heights[st.top()]){
                st.pop();
            }
            
            if(st.size()==0){
                rb[i]=n;
            }else{
                rb[i]=st.top();
                
            }
            
            st.push(i);
        }
        
        int ans=INT_MIN;
        
        for(int i=0;i<n;i++){
            int count=rb[i]-lb[i]-1;
            int area=count*heights[i];
            
            ans=max(ans,area);
        }
        
        return ans;
    }
};