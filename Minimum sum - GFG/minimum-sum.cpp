// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
string sum(string a,string b){
    string ans="";
    
    int n=a.length();
    int m=b.length();
    
    int i=n-1;
    int j=m-1;
    
    
    int carry=0;
    
    while(i>=0 || j>=0){
        int sum=0;
        if(i>=0){
            sum+=a[i]-'0';
            i--;
        }
        
        if(j>=0){
            sum+=b[j]-'0';
            j--;
        }
        
        sum+=carry;
        carry=sum/10;
        sum=sum%10;
        ans+=to_string(sum);
    }
    
    if(carry!=0){
        ans+=to_string(carry);
    }
    
    reverse(ans.begin(),ans.end());
    return ans;
}
    
    string solve(int arr[], int n) {
        // code here
        string a="";
        string b="";
        
        sort(arr,arr+n);
        
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                continue;
            }
            
            if(i%2==0){
                a+=to_string(arr[i]);
            }else{
                b+=to_string(arr[i]);
            }
            
            
        }
        
        return sum(a,b);
    }
   
    
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends