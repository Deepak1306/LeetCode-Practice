class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        unordered_map<char,int>count;
        
        for(int i=0;i<s.length();i++){
            count[s[i]]++;
        }
        
        stack<char>st;
        bool* check=new bool[26];
        
        for(int i=0;i<26;i++){
            check[i]=false;
        }
        
        
        for(int i=0;i<s.length();i++){
          char ch=s[i];
            count[ch]--;
            
            if(check[ch-'a']){
                continue;
            }
            
            while(!st.empty() && (ch-'a'<st.top()-'a') && count[st.top()]>0){
                check[st.top()-'a']=false;
                st.pop();
            }
            
            st.push(ch);
            check[ch-'a']=true;
            
        } 
        
        string str;
        while(!st.empty()){
            str=st.top()+str;
            st.pop();
        }
        
        return str;
    }
};