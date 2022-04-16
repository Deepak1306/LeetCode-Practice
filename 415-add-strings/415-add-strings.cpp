class Solution {
public:
    string helper(string num1,string num2){
       int n=num1.length();
       int m=num2.length();
        
        int carry=0;
        
        for(int i=m-1,j=n-1;i>=0;i--,j--){
            int a=num1[j]-'0';
            int b=num2[i]-'0';
            
            int sum=a+b+carry;
            carry=sum/10;
            sum=sum%10;
            char c=sum+'0';
            num1[j]=c;
        }
        
            int j=n-m-1;
            while(carry!=0 && j>=0){
                int sum=carry+num1[j]-'0';
                carry=sum/10;
                sum=sum%10;
                char c=sum+'0';
                num1[j]=c;
                j--; 
            }
         
        if(carry!=0){
            char c=carry+'0';
            num1=c+num1;
        }
        
        return num1;
        
        
    }
    
    string addStrings(string num1, string num2) {
        int n=num1.length();
        int m=num2.length();
        
        if(n>m){
            return helper(num1,num2);
        }else{
            return helper(num2,num1);
        }
    }
};