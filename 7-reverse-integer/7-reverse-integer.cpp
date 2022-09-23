class Solution {
public:
    int reverse(int x) {
        long sum=0;
        
        while(x!=0){
            sum=sum*10+ x%10;
            x=x/10;
        }
        
        if(sum<INT_MIN || sum>INT_MAX){
            return 0;
        }
        
        return sum;
    }
};