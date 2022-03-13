class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        
        if(n%2!=0){
            return false;
        }
        
        stack<char>st;
        
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            }
            
            else if(s[i]==')'){
                if(st.empty() || st.top()!='('){
                    return false;
                }
                st.pop();
                
            }else if(s[i]==']'){
                if(st.empty() || st.top()!='['){
                    return false;
                }
                st.pop();
            }else{
                if(st.empty() || st.top()!='{'){
                    return false;
                }
                st.pop();
            }
            
        }
        
        if(!st.empty()){
            return false;
        }
        
        return true;
        
    }
};