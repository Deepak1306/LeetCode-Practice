// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
     int x=0;
     for(int i=0;i<N1;i++){
         x+=S1[i];
     }
     
     int y=0;
     for(int j=0;j<N2;j++){
         y+=S2[j];
     }
     
     int z=0;
     for(int k=0;k<N3;k++){
         z+=S3[k];
     }
     
     int i=0;
     int j=0;
     int k=0;
     
     while(x>0 && y>0 && z>0){
         if(x==y && y==z){
             return x;
         }
         
         int m=min(x,min(z,y));
         
         if(x>m){
             x-=S1[i];
             i++;
         }
         
         if(y>m){
             y-=S2[j];
             j++;
         }
         
         if(z>m){
             z-=S3[k];
             k++;
         }
     }
     
     return 0;
     
     
        
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}  // } Driver Code Ends