class Solution {
public:
    void helper(vector<string>&ans, string str,int n,int open,int close){
        if(str.length()==2*n){
            ans.push_back(str);
            return;
        }
        
        if(open<n){
            helper(ans,str+"(",n,open+1,close);
        }
        
        if(close<open){
            helper(ans,str+")",n,open,close+1);
        }
        return ;
        
    }
    
    vector<string> generateParenthesis(int n) {
    
        vector<string>ans;
        helper(ans,"",n,0,0);
        return ans;
        
        
    }
};