class Solution {
public:
    bool winnerOfGame(string colors) {
         int n=colors.length();
         
        int i=1;
        int j=0;
        
        int countA=0;
        int countB=0;
        
        while(i<n-1){
            if(colors[i]==colors[j] && colors[i]==colors[i+1]){
                if(colors[i]=='A'){
                    countA++;
                }else{
                    countB++;
                }
                i++;
            }else{
                j=i;
                i++;
            }
        }
        
        
        return countA>countB;
        
        
    }
};