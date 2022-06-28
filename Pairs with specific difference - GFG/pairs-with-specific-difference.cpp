// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        // Your code goes here 
        
        sort(arr,arr+N);
        
        int i=N-2;
        int j=N-1;
        
        int sum=0;
        
        while(i>=0 && j>=0){
            if(arr[j]-arr[i]<K){
                sum+=arr[i]+arr[j];
                j=j-2;
                i=i-2;
            }else{
                i--;
                j--;
            }
        }
        
        return sum;
        
    }
};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}
  // } Driver Code Ends