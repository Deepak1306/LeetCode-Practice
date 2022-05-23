class Solution {
public:
    
    int helper(int M[],int  m){
        
        stack<int>st;
        int left[m];
        left[0]=-1;
        
        st.push(0);
        for(int i=1;i<m;i++){
            while(st.size()>0 && M[i]<=M[st.top()]){
              st.pop();  
            }
            
            if(st.size()==0){
                left[i]=-1;
            }
            else{
                left[i]=st.top();
            }
            
            st.push(i);
            
            
        }
        
        while(st.size()>0){
            st.pop();
        }
        
        
        
        int right[m];
        right[m-1]=m;
        st.push(m-1);
        
        for(int i=m-2;i>=0;i--){
            while(st.size()>0 && M[i]<=M[st.top()]){
              st.pop();  
            }
            
            if(st.size()==0){
                right[i]=m;
            }
            else{
                right[i]=st.top();
            }
            
            st.push(i);
            
        }
        
        int ans=INT_MIN;
        
        for(int i=0;i<m;i++){
            int count=right[i]-left[i]-1;
            int area=count*M[i];
            ans=max(ans,area);
        }
        
        return ans;
        
        
    }
    
    int maximalRectangle(vector<vector<char>>& M) {
       int n=M.size();
        int m=M[0].size();
         
        int arr[n][m];
        
        int ans=INT_MIN;
        
        for(int j=0;j<m;j++){
            arr[0][j]=M[0][j]-'0';
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]=='0'){
                    arr[i][j]=0;
                }else{
                    arr[i][j]=1+arr[i-1][j];
                }
            }
            
            
        }
        
        for(int i=0;i<n;i++){
            ans=max(ans,helper(arr[i],m));
        }
       
        return ans;
        
        
    }
};