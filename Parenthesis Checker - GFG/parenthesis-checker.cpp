// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool arePairs(char open, char close){
        if(open=='(' && close==')'){
            return true;
        }else if(open=='[' && close==']'){
            return true;
        }else if(open=='{' && close=='}'){
            return true;
        }else{
            return false;
        }
    }
    bool ispar(string x)
    {
        // Your code here
        int n=x.length();
        stack<char>st;
        for(int i=0;i<n;i++){
            if(x[i]=='(' || x[i]=='[' || x[i]=='{'){
                st.push(x[i]);
            }else if(x[i]==')' || x[i]==']' || x[i]=='}'){
                if(st.empty() || !arePairs(st.top(),x[i])){
                    return false;
                }
                
                st.pop();
            }
        }
        
        if(!st.empty()){
            return false;
        }
        return true;
        
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends