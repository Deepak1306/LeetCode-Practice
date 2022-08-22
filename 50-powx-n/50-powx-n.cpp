class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return (double)1;
        }
        else if(x==0){
            return (double)0;
        }else if(n==1){
            return x;
        }
        else if(n==-1){
            return 1.0/x;
        }
        
        
        double ans=myPow(x,n/2);
        
        ans*=ans;
        
        if(abs(n)%2!=0){
            if(n<0){
              ans=(1.0/x)*ans ;   
            }else{
              ans=x*ans;
            }
            
        }
        
        return ans;
        
    }
};