class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
       int n=A.size();
    int m=B.size();
    
    int i=0;
    int j=0;
    
    int k=(m+n)/2;
    
    int curr=-1;
    int prev=-1;
    
    int count=0;
    
    while(i<n && j<m && count<=k){
       if(A[i]<=B[j]){
           prev=curr;
           curr=A[i];
           i++;
       }else{
          prev=curr;
          curr=B[j];
          j++; 
       }
       count++;
    }
    
    while(i<n && count<=k){
        prev=curr;
        curr=A[i];
        i++;
        count++;
    }
    
    while(j<m && count<=k){
        prev=curr;
        curr=B[j];
        j++;
        count++;
    }
    
    if((m+n)%2==0){
        return (double)(curr+prev)/2;
    }else{
        return curr;
    }
    
    
       
        
        
    }
};