// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    long long int findMaxProduct(vector<int>&a, int n){
        //Write your code here
        int mod=1e9+7;
        
        if(n==1){
            return a[0];
        }
        
        int neg=0;
        int zero=0;
        
        long long int ans=1;
        int maxN=INT_MIN;
        
        for(int i=0;i<n;i++){
            if(a[i]==0){
                zero++;
                continue;
            }else if(a[i]<0){
                neg++;
                maxN=max(maxN,a[i]);
            }
            
            ans=(ans*a[i])%mod;
        }
        
        
        if(zero==n){
            return 0;
        }
        if(neg==1 && neg+zero==n){
            return 0;
        }
        if(neg%2!=0){
            ans=ans/maxN;
        }
        
        return ans;
  
        
    }
    
    
};



// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    long long int ans = ob.findMaxProduct(arr, n);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends