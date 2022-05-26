

class Solution {
public:
  

int solve(string A,string B,unordered_map<string,int>& map){
   string s=A+" "+B;

   int n=A.length();
   int m=B.length();
   if(n!=m){
       return 0;
   }

   if(A==B){
       return 1;
   }

   if(n<=1 || m<=1){
       return 0;
   }
    
   if(map.find(s)!=map.end()){
       return map[s];
   }

   int flag=0;

   for(int k=1;k<n;k++){

       int cond1=solve(A.substr(0,k),B.substr(n-k,k),map) && solve(A.substr(k,n-k),B.substr(0,n-k),map);
       int cond2=solve(A.substr(0,k),B.substr(0,k),map) && solve(A.substr(k),B.substr(k),map);
       
       if(cond1==1 || cond2==1){
           flag=1;
           break;
       }
   }

   return map[s]=flag;

}
    
    bool isScramble(string s1, string s2) {
           unordered_map<string,int>map;
           return solve(s1,s2,map);
   
    }
};