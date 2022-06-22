// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int S, int D){
        // code here
        if(D*9<S){
            return "-1";
        }
        
        if(D==1){
            return to_string(S);
        }
        
        string s="";
        while(S>0){
            if(S<=9){
                int a=0;
                if(D==1){
                    a=S;
                }else{
                  a=S-1;    
                }
                char c=a+'0';
                
                s=c+s;
                S=S-a;
                D--;
            }
            else{
                int a=9;
                S=S-a;
                
                char c=a+'0';
                
                s=c+s;
                D--;
            }
            
        }
        return s;
        
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
}   // } Driver Code Ends