class Solution {
public:
    string simplifyPath(string path) {
        int n=path.length();
        
        string str;
        stack<string>st;
    
        for(int i=0;i<n;i++){
            if(path[i]=='/'){
                continue;
            }
            string temp;
            while(i<n && path[i]!='/'){
                temp+=path[i];
                i++;
            }
            
            if(temp=="."){
                continue;
            }else if(temp==".."){
                if(!st.empty()){
                    st.pop();
                }
            }else{
                st.push(temp);
            }
        
            
        }
        
        while(!st.empty()){
            str="/"+st.top()+str;
            st.pop();
        }
        if(str.empty()){
            return "/";
        }
        
        return str;
    }
};