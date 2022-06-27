// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
          //code here
          pair<int,int>ans={0,INT_MAX};
          
          priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
          int mini=INT_MAX;
          int maxi=INT_MIN;
          
          for(int i=0;i<k;i++){
              pq.push({arr[i][0],{i,0}});
              maxi=max(maxi,arr[i][0]);
          }
          
          while(!pq.empty()){
              mini=pq.top().first;
              int x=pq.top().second.first;
              int y=pq.top().second.second;
              pq.pop();
              
              if(maxi-mini < ans.second-ans.first){
                  ans={mini,maxi};
              }
              
              if(y+1>=n){
                  break;
              }
              
              maxi=max(maxi,arr[x][y+1]);
              pq.push({arr[x][y+1],{x,y+1}});
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
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends