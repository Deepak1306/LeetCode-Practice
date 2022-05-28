// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	    // Your code goes here
	    int n=S.length();
	    
	    int zeros=0;
	    int ones=0;
	    
	    vector<int>v(n);
	    for(int i=0;i<S.length();i++){
	        if(S[i]=='0'){
	            v[i]=1;
	        }else{
	            v[i]=-1;
	        }
	    }
	    
	    int ans=v[0];
	    int sum=v[0];
	    for(int i=1;i<n;i++){
	        if(sum+v[i]<v[i]){
	            sum=v[i];
	        }
	        else{
	            sum+=v[i];
	        }
	        
	        ans=max(sum,ans);
	        
	    }
	   
	    
	    
	    
	    return ans;
	    
	    
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends