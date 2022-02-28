// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends



int countRev (string s)
{
    // your code here
    stack<char>st;
    
    for(int i=0;i<s.length();i++){
        if(s[i]=='{'){
            st.push(s[i]);
        }else if(!st.empty()&&st.top()=='{'){
            st.pop();
        }else{
            st.push(s[i]);
        }
    }
    
    
    int count=0;
    while(!st.empty()){
        char c1=st.top();
        st.pop();
        
        if(st.empty()){
            return -1;
        }
        
        char c2=st.top();
        st.pop();
        
        if(c1!=c2){
            count+=2;
        }else{
            count+=1;
        }
        
    }
    
    return count;
    
    
}