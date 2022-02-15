// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	
	void helper(string S,string t, vector<string>&ans){
	       int n=S.length();
	       if(n==0){
	           ans.push_back(t);
	        return ;
	       }
	       
	       for(int i=0;i<n;i++){
	           string str=S.substr(i+1)+S.substr(0,i);
	           
	           helper(str,t+S[i],ans);
	       }
		    return ;
		
	}
		vector<string>find_permutation(string S)
		{
		    // Code here there
		 
		    vector<string>ans;
		    int n=S.length();
		    if(n==0){
		        return ans; 
		    }
		    
		    helper(S,"",ans);
		    sort(ans.begin(),ans.end());
		    
		    return ans;
		    
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends