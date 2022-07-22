class Solution {
public:
    int ladderLength(string A, string B, vector<string>& C) {
          unordered_set<string>m(C.begin(),C.end());
    
    queue<string>q;
    q.push(A);
    int ans=1;
    
    while(!q.empty()){
        
        int size=q.size();
        
        while(size--){
           string s=q.front();
           q.pop();
           
            if(s==B){
                return ans;
            }
           
           for(int i=0;i<s.length();i++){
            char ch=s[i];
            for(int j=0;j<26;j++){
                s[i]=j+'a';
                if(m.find(s)!=m.end()){
                    q.push(s);
                    m.erase(s);
                }
               
            }
             s[i]=ch;
          }     
        }
        ans++;
    }
    
    return 0;
        
    }
};