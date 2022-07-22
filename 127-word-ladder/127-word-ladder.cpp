class Solution {
public:
    int ladderLength(string A, string B, vector<string>& C) {
          unordered_set<string>m(C.begin(),C.end());
    
    queue<pair<string,int>>q;
    q.push({A,1});
    
    while(!q.empty()){
        string s=q.front().first;
        int c=q.front().second;
        q.pop();
        m.erase(s);
        if(s==B){
            return c;
        }
        
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            for(int j=0;j<26;j++){
                s[i]=j+'a';
                 if(m.find(s)!=m.end()){
                    q.push({s,c+1});
                }
               
            }
             s[i]=ch;
        }    
    }
    
    return 0;
        
    }
};