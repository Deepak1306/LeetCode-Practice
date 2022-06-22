// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here  
        
        vector<long long int>ans;
        
        if(n==1){
            return {1};
        }
        vector<long long int>left(n);
        vector<long long int>right(n);
        
        long long int s=1;
        for(int i=0;i<n;i++){
            s=s*nums[i];
            left[i]=s;
        }
        
        s=1;
        for(int i=n-1;i>=0;i--){
            s=s*nums[i];
            right[i]=s;
        }
        
        
        for(int i=0;i<n;i++){
            if(i==0){
               ans.push_back(right[i+1]);    
            }
            else if(i==n-1){
               ans.push_back(left[i-1]);
            }
            else{
               ans.push_back(left[i-1]*right[i+1]); 
            }
            
        }
        return ans;
    }
};


// { Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends