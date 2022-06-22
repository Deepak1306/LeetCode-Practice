// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int>ans;
    
    int i=0;
    int j=n-1;
    
    
    int k=-1;
    int m=-1;
    
    while(i<=j){
        int mid=i+(j-i)/2;
        
        if(arr[mid]==x){
            k=mid;
            j=mid-1;
        }else if(arr[mid]>x){
            j=mid-1;
        }else{
            i=mid+1;
        }
        
    }
    
    i=0;
    j=n-1;
    while(i<=j){
        int mid=i+(j-i)/2;
        
        if(arr[mid]==x){
            m=mid;
            i=mid+1;
        }else if(arr[mid]>x){
            j=mid-1;
        }else{
            i=mid+1;
        }
    }
    
    ans.push_back(k);
    ans.push_back(m);
    
    return ans;
    
    
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends