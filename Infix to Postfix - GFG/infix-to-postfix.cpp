// { Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        // Your code here
        unordered_map<char,int>m;
        
        m['+']=1;
        m['-']=1;
        m['*']=2;
        m['/']=2;
        m['^']=3;
        
        stack<char>st;
        
        string str="";
        for(int i=0;i<s.length();i++){
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
                str+=s[i];
            }
            else if(st.empty()){
                st.push(s[i]);
            }
            else if(s[i]=='('){
                st.push(s[i]);
            }else if(s[i]==')'){
                while(!st.empty() && st.top()!='('){
                    str+=st.top();
                    st.pop();
                }
                st.pop();
                
            }else{
                if(m[s[i]]>m[st.top()]){
                    st.push(s[i]);
                }
                else{
                    while(!st.empty() && m[s[i]]<=m[st.top()]){
                        str+=st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                }
                
                
                
            }
            
        }
        
        while(!st.empty()){
            str+=st.top();
            st.pop();
        }
        
        return str;
        
        
    }
};


// { Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}
  // } Driver Code Ends