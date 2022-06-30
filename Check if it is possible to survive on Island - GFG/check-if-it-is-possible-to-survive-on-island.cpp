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
        
        if(M>N){
            return -1;
        }
        
        if(M*7>N*6 && S>6){
            return -1;
        }
        
        
        int count=0;
        int curr=0;
        
        while(S>0){
            if(curr>=M){
               curr-=M;
               S--;
               continue;
                
            }
            
            count++;
            S--;
            curr+=N-M;
            
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