// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int maxSum(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;++i)
			cin>>arr[i];
		cout<<maxSum(arr,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


long long int maxSum(int arr[], int n)
{
    sort(arr,arr+n);
    
    int i=0;
    int j=n-1;
    
    long long int ans=0;
    
    while(i<j){
        ans+=abs(arr[j]-arr[i]);
        i++;
        ans+=abs(arr[j]-arr[i]);
        j--;
    }
    
    ans+=abs(arr[0]-arr[i]);
    
    return ans;
    
}