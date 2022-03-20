class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        unordered_map<int,int>map;
        int top=0;
        int count=0;
        
        for(int i=0;i<tops.size();i++){
            map[tops[i]]++;
                 
            if(count<map[tops[i]]){
                count=map[tops[i]];
                top=tops[i];
            }
            
            
            
        }
        
        map.clear();
        
        int bottom=0;
        count=0;
        for(int i=0;i<bottoms.size();i++){
            map[bottoms[i]]++;
                 
            if(count<map[bottoms[i]]){
                count=map[bottoms[i]];
                bottom=bottoms[i];
            }
        }
        bool check1=true;
        int ans1=0;
        for(int i=0;i<tops.size();i++){
            if(tops[i]==top){
                continue;
            }
            
            else if(tops[i]!=top && bottoms[i]!=top){
                check1=false;
                break;
            }else{
                ans1++;
            }
        }
        
        
        
        bool check2=true;
        int ans2=0;
        for(int i=0;i<bottoms.size();i++){
            if(bottoms[i]==bottom){
                continue;
            }
            else if(bottoms[i]!=bottom && tops[i]!=bottom){
                check2=false;
                break;
            }else{
                ans2++;
            }
        }
        
        if(check1 && check2){
            return min(ans1,ans2);
        }
        else if(!check1 && check2){
            return ans2;
        }else if(check1 && !check2){
            return ans1;
        }
        else{
            return -1;
        }
    
    }
};