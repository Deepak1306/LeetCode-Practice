// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        map<char,int>m;
        
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        
        priority_queue<int>pq;
        
        for(auto i:m){
            pq.push(i.second);
        }
        
        for(int i=1;i<=k;i++){
            int a=pq.top();
            pq.pop();
            a--;
            pq.push(a);
        }
        
        int count=0;
        while(!pq.empty()){
            count+=pq.top()*pq.top();
            pq.pop();
            
        }
        
        return count;
        
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}  // } Driver Code Ends