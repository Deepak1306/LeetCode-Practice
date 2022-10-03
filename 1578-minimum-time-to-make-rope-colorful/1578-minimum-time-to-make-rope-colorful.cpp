class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        int i=0;
        int j=1;
        
        int ans=0;
        
        while(j<n){
           if(colors[i]==colors[j]){
               int a=min(neededTime[i],neededTime[j]);
               ans+=a;
               
               if(neededTime[i]==a){
                  i=j;
                  j++;
               }else{
                  j++; 
               }
           }else{
                   i=j;
                   j++;
           }    
        }
        
        return ans;
    }
};