// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    static bool comp(pair<int,int>a,pair<int,int>b){
        if(a.first==b.first){
            return a.second<b.second;
        }
        
        return a.first<b.first;
    } 

    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        
        vector<pair<int,int>>v(n);
        
        for(int i=0;i<n;i++){
            v[i]={price[i],i+1};
        }
        
        sort(v.begin(),v.end(),comp);
        
        int count=0;
        for(int i=0;i<n;i++){
            if(v[i].first>k){
                break;
            }
            
            int temp=k/v[i].first;
            if(temp<v[i].second){
                count+=temp;
                k-=temp*v[i].first;
            }else{
                count+=v[i].second;
                k-=v[i].second*v[i].first;
            }
            
        }
        
        return count;
        
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends