class Solution {
public:    
   static bool comp(vector<int> &a,vector<int> &b){
       if(a[0]==b[0]){
           return a[1]<b[1];
       }
       
       return a[0]>b[0];
   }
    
    int numberOfWeakCharacters(vector<vector<int>>& arr) {
        int n=arr.size();
        int count=0;
        
        sort(arr.begin(),arr.end(),comp);
        
        int mx=arr[0][1];
        int att=arr[0][0];
        
        int i=1;
        
        while(i<n){
            
            if(arr[i][0]!=att){
                if(arr[i][1]<mx){
                    count++;
                }else if(mx<arr[i][1]){
                    mx=arr[i][1];
                    att=arr[i][0];
                }      
            }else{
                mx=max(mx,arr[i][1]);
            }
            
            i++;
        }
        return count;
    }
};