class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
     
        int n=tops.size();
        int top=tops[0];
      int bot=bottoms[0];
        
        int top1=0;
        int top2=0;
        int bot1=0;
        int bot2=0;
        
        for(int i=0;i<tops.size();i++){
            if(tops[i]!=top && bottoms[i]!=top){
                top=0;
            }
            
            if(bottoms[i]!=bot && tops[i]!=bot){
                bot=0;
            }
            
            
            top1+=tops[i]==top;
            bot1+=bottoms[i]==top;
            top2+=tops[i]==bot;
            bot2+=bottoms[i]==bot;
            
        }
        
        return top||bot ? min(n-max(top1,bot1),n-max(top2,bot2)) : -1;
    
    }
};