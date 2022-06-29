// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
int dp[501][2001];
class Solution {
public:
    
    int solve(int i, int rem, vector<int>arr, int k){
        if(i==arr.size()){
            return 0;
        }
        
        if(dp[i][rem]!=-1){
            return dp[i][rem];
        }
        
        int ans=INT_MAX;
        
        if(arr[i]>rem){
            int count=(rem+1)*(rem+1)+solve(i+1,k-arr[i]-1,arr,k);
            ans=min(ans,count);
        }else{
            int choice1=(rem+1)*(rem+1)+solve(i+1,k-arr[i]-1,arr,k);
            int choice2=solve(i+1,rem-arr[i]-1,arr,k);
            
            ans=min(ans,min(choice1,choice2));
        }
        
        return dp[i][rem]=ans;
        
        
        
        
    }
    
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        
        memset(dp,-1,sizeof(dp));
        return solve(0,k,nums,k);
    } 
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}  // } Driver Code Ends