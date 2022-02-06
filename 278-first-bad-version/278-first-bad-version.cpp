// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i=1;
        int j=n;
        
        if(n==1){
            return 1;
        }
       
        
        while(i<=j){
            int mid=i+(j-i)/2;
            
            if(isBadVersion(mid) &&(mid==1 || !isBadVersion(mid-1))){
                return mid;
                
            }else if(!isBadVersion(mid)){
                i=mid+1;
            }else{
                j=mid-1;
            }
               
        }
        
        return -1;
    }
};