 string str[]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
class Solution {
public:
    void helper(vector<string>&ans,string digits,string output){
        int n=digits.length();
        
        if(n==0){
            ans.push_back(output);
            return ;
        }
        
        
        int a=digits[0]-'2';
        string s=str[a];
        
        for(int i=0;i<s.length();i++){
            helper(ans,digits.substr(1),output+s[i]);
        }
        
        return ;
        
        
    }
   
    vector<string> letterCombinations(string digits) {
       vector<string>ans;
        int n=digits.length();
        if(n==0){
            return ans;
        }
        
        helper(ans,digits,"");
        
        return ans;
        
    }
};