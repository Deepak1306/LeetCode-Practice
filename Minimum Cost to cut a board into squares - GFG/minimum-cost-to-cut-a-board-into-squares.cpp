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
        int x=1;
        int y=1;
        
        sort(X.begin(),X.end());
        sort(Y.begin(),Y.end());
        
        int total=0;
        
        int i=X.size()-1;
        int k=Y.size()-1;
        
        while(i>=0 && k>=0){
            if(X[i]<=Y[k]){
                total+=Y[k]*x;
                y++;
                k--;
            }else{
                total+=X[i]*y;
                x++;
                i--;
            }
        }
        
        while(k>=0){
            total+=Y[k]*x;
            k--;
            y++;
        }
        
        while(i>=0){
            total+=X[i]*y;
            i--;
            x++;
        }
        
        return total;
        
        
        
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