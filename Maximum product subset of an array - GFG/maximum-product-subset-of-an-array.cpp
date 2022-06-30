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
        
        int minA=INT_MIN;
        
        if(n==1){
            return a[0];
        }
        
        
        int neg=0;
        int zero=0;
        
        
        int mod=1e9+7;
        long long int ans=1;
        
        for(int i=0;i<a.size();i++){
            
            if(a[i]==0){
                zero++;
                continue;
            }
            
            ans*=a[i];
            ans=ans%mod;
            
            if(a[i]<0){
                neg++;
                minA=max(minA,a[i]);
            }
            
            
            
            
        }
        
        if(neg==1 && zero==n-1){
            return 0;
        }
        
        if(neg%2==0){
            return ans%mod;
        }else if(neg%2!=0){
            return (ans/minA)%mod;
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