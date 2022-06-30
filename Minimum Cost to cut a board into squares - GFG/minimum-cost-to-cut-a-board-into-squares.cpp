// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N){
        //Write your code here
        sort(X.begin(),X.end());
        sort(Y.begin(),Y.end());
        
        int i=X.size()-1;
        int j=Y.size()-1;
        
        int x=1;
        int y=1;
        
        int cost=0;
        
        while(i>=0 && j>=0){
            if(Y[j]>=X[i]){
                cost+=Y[j]*x;
                y++;
                j--;
            }else{
                cost+=X[i]*y;
                x++;
                i--;
            }
        }
        
        while(i>=0){
                cost+=X[i]*y;
                x++;
                i--;
        }
        
        while(j>=0){
                cost+=Y[j]*x;
                y++;
                j--;
            
            
        }
        
        return cost;
        
    }
};



// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int m, n;
	    cin >> m >> n;
	    vector<int>X(m - 1), Y(n - 1);
	    for(int i = 0; i < m - 1; i++){
	        cin >> X[i];
	    }
	    for(int i = 0; i < n - 1; i++){
	        cin >> Y[i];
	    }
	    Solution ob;
	    int ans = ob.minimumCostOfBreaking(X, Y, m - 1, n - 1);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends