// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        
        int *arr1=new int[n+1];
        for(int i=1;i<=n;i++){
            arr1[i]=0;
        }
        int *ans=new int[2];
        for(int i=0;i<n;i++){
            if(arr1[arr[i]]==-1){
                ans[0]=arr[i];
                continue;
            }
            
            arr1[arr[i]]=-1;
        }
        
        for(int i=1;i<=n;i++){
            if(arr1[i]==0){
                ans[1]=i;
                break;
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends