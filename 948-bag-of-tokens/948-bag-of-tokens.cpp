class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
         int n=tokens.size();
         int i=0;
         int j=n-1;
        int count=0;
        int ans=0;
        
        sort(tokens.begin(),tokens.end());
        
        while(i<=j){
            if(tokens[i]>power){
                if(count==0){
                  return ans;  
                }
                
                power+=tokens[j];
                j--;
                count--;
                
            }else{
                count++;
                power-=tokens[i];
                i++;
            }
            
            ans=max(ans,count);
        }
        
        return ans;
        
        
    }
};