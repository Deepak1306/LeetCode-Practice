// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
   static bool compare(Job a1, Job a2){
        return a1.profit>a2.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        int max=0;
        
        for(int i=0;i<n;i++){
            if(arr[i].dead>max){
                max=arr[i].dead;
            }
        }
        
        
        int dp[max+1];
        
        memset(dp,-1,sizeof(dp));
        
        sort(arr,arr+n,compare);
        
        int profit=0;
        int count=0;
        for(int i=0;i<n;i++){
            
          for(int j=arr[i].dead;j>=1;j--){
              if(dp[j]==-1){
                  dp[j]=i;
                  profit+=arr[i].profit;
                  count++;
                  break;
              }
          }    
        
        }
        
        vector<int>ans;
        ans.push_back(count);
        ans.push_back(profit);
        return ans;
        
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends