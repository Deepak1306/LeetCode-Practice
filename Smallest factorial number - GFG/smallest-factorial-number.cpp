// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
        int findNum(int n)
        {
        //complete the function here
        int num=1;
        int m=5*n;
        
        while(num<m){
            int count=0;
            int mid=num+(m-num)/2;
            
            for(int i=5;i<=mid;i*=5){
                count+=(mid/i);
            }
            
            if(count<n){
                num=mid+1;
            }
            else{
                m=mid;
            }
        }
        
        return num;
        
        }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends