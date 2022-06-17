// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<int>left(n);
        left[0]=-1;
        
        stack<long long>st;
        st.push(0);
        
        for(int i=1;i<n;i++){
            while(!st.empty() && arr[i]<=arr[st.top()]){
                st.pop();
            }
            
            if(st.empty()){
                left[i]=-1;
            }else{
                left[i]=st.top();
            }
            
            st.push(i);
            
        }
        
        
        while(!st.empty()){
            st.pop();
        }
        
        
        vector<int>right(n);
        right[n-1]=n;
        st.push(n-1);
        
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && arr[i]<=arr[st.top()]){
                st.pop();
            }
            
            if(st.empty()){
                right[i]=n;
            }else{
                right[i]=st.top();
            }
            
            st.push(i);
            
        }
        long long  ans=INT_MIN;
        for(long long i=0;i<n;i++){
            long long count=arr[i]*(right[i]-(left[i]+1));
            
            ans=max(ans,count);
        }
        return ans;
        
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends