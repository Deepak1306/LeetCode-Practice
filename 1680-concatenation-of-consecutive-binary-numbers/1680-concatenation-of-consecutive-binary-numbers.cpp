class Solution {
public:
     
    int concatenatedBinary(int n) {
        
    
        int i=n;
        int j=n;
        int mod=1e9+7;
        long count=0;
        long x=1;
        while(j>0){
            while(i>0){
               int y=i%2;
                i=i/2;
                
                if(y!=0){
                    count=count+x;
                    count%=mod;
                }
                x*=2;
                x%=mod;
            }
            
            j--;
            i=j;
        }
        
        return count%mod;
        
    }
};