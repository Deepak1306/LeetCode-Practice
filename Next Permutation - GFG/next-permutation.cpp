// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        int n=arr.size();
        
        if(n==1){
            return arr;
        }
        
        if(arr[n-1]>arr[n-2]){
            swap(arr[n-1],arr[n-2]);
            return arr;
        }else if(n==2){
            sort(arr.begin(),arr.end());
            return arr;
        }else{
            int j=n-3;
            int i=n-2;
            
            while(j>=0){
                if(arr[j]>=arr[i]){
                    j--;
                    i--;
                    continue;
                }
                int num=arr[j];
                sort(arr.begin()+j+1,arr.end());
                
                int k=j+1;
                while(arr[k]<=num && k<n){
                    k++;
                }
                
                swap(arr[k],arr[j]);
                
                sort(arr.begin()+j+1,arr.end());
                return arr;
                
            }
        }
        
        sort(arr.begin(),arr.end());
        
        return arr;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends