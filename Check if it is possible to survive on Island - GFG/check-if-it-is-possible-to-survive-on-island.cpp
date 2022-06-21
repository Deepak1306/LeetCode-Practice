// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int S, int N, int M){
        // code here
        int days=0;
        int count=0;
        
        if(N<M || (N*6 <M*7 &&S>6)){
            return -1;
        }
        int curr=0;
        
        while(days<S){
            
            
            
          if(curr<M){
              count++;
              curr+=N;
          }
          curr-=M;
          days++;
          
          
        }
        return count;
        
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}  // } Driver Code Ends