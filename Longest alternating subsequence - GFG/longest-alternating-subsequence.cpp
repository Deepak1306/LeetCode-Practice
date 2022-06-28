// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int AlternatingaMaxLength(vector<int>&nums){
		    // Code here
		    
		    int l1=1;
		    int l2=1;
		    
		    for(int i=1;i<nums.size();i++){
		        
		       if(nums[i]>nums[i-1]){
		           l1=l2+1;
		       }else if(nums[i-1]>nums[i]){
		           l2=l1+1;
		       } 
		        
		    }
		    
		    return max(l1,l2);
		    
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.AlternatingaMaxLength(nums);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends