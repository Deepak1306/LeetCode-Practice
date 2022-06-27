// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    priority_queue<int>max;
    priority_queue<int,vector<int>,greater<int>>min;
    
    public:
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(max.size()==0 || x<=max.top()){
            max.push(x);
        }else{
            min.push(x);
        }
        
        balanceHeaps();
        
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(max.size()>min.size()+1){
            min.push(max.top());
            max.pop();
        }
        
        else if(min.size()>max.size()){
            max.push(min.top());
            min.pop();
        }
        
    }
    
    //Function to return Median.
    double getMedian()
    { 
        if(max.size()==min.size()){
            return ((double)max.top()+(double)min.top())/2;
        }else{
            return max.top();
        }
        
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends