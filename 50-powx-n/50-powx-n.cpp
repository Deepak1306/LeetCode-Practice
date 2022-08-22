class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return (double)1;
        }
        else if(x==0){
            return (double)0;
        }
        
        
        if(n<0){
            x=1.0/x;
        }
        
        double ans=myPow(x,abs(n)/2);
        
        ans*=ans;
        
        if(abs(n)%2!=0){
            ans=x*ans;
        }
        
        return ans;
        
    }
};