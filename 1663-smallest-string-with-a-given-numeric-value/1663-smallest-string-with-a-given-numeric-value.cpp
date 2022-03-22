class Solution {
public:

   
    string getSmallestString(int n, int k) {
        
       string str;
        
        for(int i=0;i<n;i++){
            str+='a';
        }
        
        k-=n;
        
        int i=n-1;
        while(k>0){
            int temp=min(k,25);
            
            str[i]+=temp;
            i--;
            k-=temp;
            
            
        }
        
        return str;
        
    }
};