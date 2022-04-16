class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        
        int carry=1;
        int j=n-1;
        while(carry!=0 && j>=0){
            int sum=digits[j]+carry;
            carry=sum/10;
            sum=sum%10;
            
            digits[j]=sum;
            j--;
        }
        
        if(carry!=0){
            digits.insert(digits.begin(),carry);
        }
        
        return digits;
        
    }
};