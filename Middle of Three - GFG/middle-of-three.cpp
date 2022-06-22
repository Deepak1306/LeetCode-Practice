// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int middle(int A, int B, int C){
        //code here
        //Position this line where user code will be pasted.
        
        int maxN=max(A,max(B,C));
        int minN=min(A,min(B,C));
        
        if(A<maxN && A>minN){
            return A;
        }else if(B<maxN && B>minN){
            return B;
        }else{
            return C;
        }
        
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int A,B,C;
        cin>>A>>B>>C;
        Solution ob;
        cout<<ob.middle(A,B,C) <<"\n";
    }
    return 0;
}  // } Driver Code Ends