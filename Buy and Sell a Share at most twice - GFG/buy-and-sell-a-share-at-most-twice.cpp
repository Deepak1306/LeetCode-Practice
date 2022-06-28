// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

int maxProfit(vector<int>&price){
    //Write your code here..
    int n=price.size();
    
    
    long long left[n];
    left[0]=0;
    
    int buy=price[0];
    for(int i=1;i<n;i++){
        if(buy>price[i]){
            buy=price[i];
        }
        
        long long sell=price[i]-buy;
        
        left[i]=max(left[i-1],sell);
    }
    
    long long right[n];
    right[n-1]=0;
    
    int sell=price[n-1];
    
    for(int i=n-2;i>=0;i--){
        if(sell<price[i]){
        sell=price[i];    
        }
        
        long long count=sell-price[i];
        
        right[i]=max(right[i+1],count);
        
        
    }
    
    long long ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,left[i]+right[i]);
    }
    
    return ans;
}

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}
  // } Driver Code Ends