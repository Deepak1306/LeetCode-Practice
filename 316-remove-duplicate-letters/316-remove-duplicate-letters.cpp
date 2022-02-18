class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        int n=s.length();
        if(n==0){
            return "";
        }
        
        unordered_map<char,int>map;
        
        for(int i=0;i<n;i++){
            map[s[i]]++;
        }
        
        bool arr[26];
        for(int i=0;i<26;i++){
            arr[i]=false;
        }
        
        stack<char>st;
        for(int i=0;i<n;i++){
            char ch=s[i];
            
            map[ch]--;
            
            if(arr[ch-'a']==true){
                continue;
            }
            
            while(!st.empty() && (ch-'a'<st.top()-'a') && map[st.top()]>0){
                arr[st.top()-'a']=false;
                st.pop();
            }
            
            arr[ch-'a']=true;
            st.push(ch);
        }
        
        string str;
        
        while(!st.empty()){
            str=st.top()+str;
            st.pop();
        }
        
        return str;
        
    }
};