class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
       
        int n=s.length();
        bool dp[n];
        
        
        unordered_map<string,int>m;
        
        for(int i=0;i<wordDict.size();i++){
           m[wordDict[i]]=1;    
        }
        
        for(int i=0;i<n;i++){
            dp[i]=false;
            for(int j=0;j<=i;j++){
                string str=s.substr(j,i-j+1);
                
                if(m.find(str)!=m.end()){
                    dp[i]=true;
                    
                    if(j>0){
                        dp[i]=dp[i]&&dp[j-1];
                    }
                    
                    if(dp[i]==true){
                        break;
                    }
                }
                
                
            }
        }
        
        
        return dp[n-1];
    }
};