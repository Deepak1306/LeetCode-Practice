// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}// } Driver Code Ends


// User function Template for C++

// Function to reverse first k elements of a queue.
void reverse(queue<int>&q,int k,int &i,queue<int>&ans){
    if(q.empty()){
        return ;
    }
    
    if(i==k){
        return ;
    }
    
    int x=q.front();
    q.pop();
    i++;
    reverse(q,k,i,ans);
    ans.push(x);
    
}


queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    int i=0;
    queue<int>ans;
    reverse(q,k,i,ans);
    while(!q.empty()){
        ans.push(q.front());
        q.pop();
    }
    return ans;
    
    
}