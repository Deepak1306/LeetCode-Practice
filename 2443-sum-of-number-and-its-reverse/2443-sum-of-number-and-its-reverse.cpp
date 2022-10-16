class Solution {
public:
    int length(int n){
        int count=0;
        
        while(n){
            count++;
            n=n/10;
        }
        return count;
    }
    
    int reverse(int n){
        int sum=0;
        
        while(n){
            sum=sum*10+(n%10);
            n/=10;
        }
        
        return sum;
    }
    
    int solve(int n, long a,long b,int carry,int c,int num){
        
        n-=carry;
        carry=0;
        
        
        if(length(a)>c || length(b)>c){
            return 0;
        }else if(n<0){
            return 0;
            
        }else if(n==0){
            
            if(((a+b==num) && (a==b || a==reverse(b)))&& carry==0){
                cout<<a<<" "<<b<<endl;
                return 1;
            }else{
                return 0;
            }
            
        }
            // else if(dp[n][a]!=-1){
        //     return dp[n][a];
        // }
        
        
        int x=n%10;
        int f=0;    
        
        
       
        for(int i=0;i<=9;i++){
            
            if(i>x){
                carry=1;
                x=10+x;
            }
            
            // a=a*10+x-i;
            // b=b*10+i;
            
            if(solve(n/10,a*10+x-i,b*10+i,carry,c,num)){
                return 1;
            }
            // carry=0;
            
            
        }
        
        return 0;
        
    }
    
    
    bool sumOfNumberAndReverse(int num) {
       
        // vector<vector<int>>dp(num+1,vector<int>(num+1,-1));
        int x=length(num);
        
        
        if(solve(num,0,0,0,x,num)){
            return true;
        }else{
            return false;
        }
        
        
    }
};