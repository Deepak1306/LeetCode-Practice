class Solution {
public:
    int findMin(vector<int>& arr) {
        
        int j=arr.size()-1;
        int i=0;
        
        while(i<j){
           int mid=i+(j-i)/2;
            
          if(arr[mid]>arr[j]){
              i=mid+1;
          }else{
              j=mid;
          }
            
        }
        
        return arr[i];
    }
};