class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& arr) {
        int n=arr.size();
        map<string,int>mp;
        
        
        
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        
        int m=beginWord.length();
        
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
                
                string s=q.front().first;
                int d=q.front().second;
            
                q.pop();
            
                if(s==endWord){
                  return d;
                }
            
              for(int i=0;i<m;i++){
                 char c=s[i];
                 for(int j=0;j<26;j++){
                     
                     if(j==c-'a'){
                         continue;
                     }
                     
                     s[i]=j+'a';
                    
                    if(mp.find(s)!=mp.end()){
                        q.push({s,d+1});
                        mp.erase(s);
                    }
                    
                }
                 s[i]=c;
           }
          
        }
        
        return 0;
        
    }
};