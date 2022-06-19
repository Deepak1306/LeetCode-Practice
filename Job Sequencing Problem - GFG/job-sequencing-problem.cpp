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

bool compare(Job a1,Job a2){
    return a1.profit>a2.profit;
}
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        int d=0;
        for(int i=0;i<n;i++){
            if(d<arr[i].dead){
                d=arr[i].dead;
            }
        }
        
        sort(arr,arr+n,compare);
        
        
        int ans=0;
        int count=0;
        int dp[d+1];
        memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead;j>=1;j--){
              if(dp[j]==-1){
                  dp[j]=i;
                  ans+=arr[i].profit;
                  count++;
                  break;
              }
                
            }
        }
        
        vector<int>a;
        a.push_back(count);
        a.push_back(ans);
        return a;
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