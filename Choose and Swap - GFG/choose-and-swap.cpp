// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    string chooseandswap(string a){
        // Code Here
        
        set<char>s;
        for(int i=0;i<a.length();i++){
            s.insert(a[i]);
        }
        
        for(int i=0;i<a.length();i++){
            s.erase(a[i]);
            if(s.empty()){
                break;
            }
            
            
            char c=*s.begin();
            if(c<a[i]){
                char ch=a[i];
                for(int j=0;j<a.length();j++){
                    if(a[j]==ch){
                        a[j]=c;
                    }
                    else if(a[j]==c){
                        a[j]=ch;
                    }
                }
                break;
            }
            
        }
        return a;
        
    }
    
};


// { Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
  // } Driver Code Ends