// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int kthLargest(vector<int> &arr,int N,int K){
        
        priority_queue<int>pq;
        
        for(int i=0;i<N;i++){
            int sum=arr[i];
            pq.push(sum);
            
            for(int j=i+1;j<N;j++){
                sum+=arr[j];
                pq.push(sum);
            }
        }
        
        for(int i=0;i<K-1;i++){
            pq.pop();
        }
        
        return pq.top();
        
        
    }
};

// { Driver Code Starts.

int main(){
    
    int T;
    cin>>T;
    while(T--){
        int N,K;
        cin>>N;
        cin>>K;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        int ans=ob.kthLargest(Arr,N,K);
        cout<<ans<<endl;
    }
    return 0;
}  // } Driver Code Ends