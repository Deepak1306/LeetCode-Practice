// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  int areaHistogram(int M[],int m) {      
      
        
        int*lb=new int[m];
        stack<int> st;
        lb[0]=-1;
        st.push(0);
        for(int i=1;i<m;i++){
            while(st.size()>0 && M[i]<=M[st.top()]){
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
        
      
        
        int*rb=new int[m];
        rb[m-1]=m;
        st.push(m-1);
        for(int i=m-2;i>=0;i--){
            while(st.size()>0 && M[i]<=M[st.top()]){
                st.pop();
            }
            
            if(st.size()==0){
                rb[i]=m;
            }else{
                rb[i]=st.top();
            }
            
            st.push(i);
        }
          int ans=0;
        
        for(int i=0;i<m;i++){
            int count=rb[i]-lb[i]-1;
            int area=count*M[i];
            
            ans=max(ans,area);
        }
        
        return ans;
          
        }
  
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        
        
        int ans=areaHistogram(M[0],m);
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(M[i][j]==1){
                  M[i][j] += M[i-1][j];  
                }
                
            }
            ans= max(ans,areaHistogram(M[i],m));
            
        }
        return ans;
    }
  
  
    
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends