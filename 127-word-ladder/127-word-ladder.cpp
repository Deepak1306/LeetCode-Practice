class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>m(wordList.begin(),wordList.end());
        
        
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        
        while(!q.empty()){
            string s=q.front().first;
            int a=q.front().second;
            q.pop();
            if(s==endWord){
                return a;
            }
            m.erase(s);
            
            for(int i=0;i<s.length();i++){
               char c=s[i];
                for(int j=0;j<26;j++){
                    s[i]=j+'a';
                    if(m.find(s)!=m.end()){
                        q.push({s,a+1});
                    }
                }
                s[i]=c;
            }
            
        }
        
        return 0;
        
        
    }
};