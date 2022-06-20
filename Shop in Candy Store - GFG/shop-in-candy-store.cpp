// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    int findMin(int candies[], int n, int k){
        sort(candies,candies+n);
        
        int ans=0;
        int count=0;
        for(int i=0;i<n && count<n;i++){
           ans+=candies[i];
           count+=k+1;
        }
        
        
        return ans;
        
        
    }
    int findMax(int candies[], int n, int k){
        sort(candies,candies+n);
        
          int ans=0;
        int count=0;
        for(int i=n-1;i>=0 && count<n;i--){
           ans+=candies[i];
           count+=k+1;
        }
        
        
        return ans;
    
        
    }
   
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        int min=findMin(candies,N,K);
        int max=findMax(candies,N,K);
        
        vector<int>ans;
        
        ans.push_back(min);
        ans.push_back(max);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends