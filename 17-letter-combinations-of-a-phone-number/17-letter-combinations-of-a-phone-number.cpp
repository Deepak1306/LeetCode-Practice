 string str[]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
class Solution {
public:
    vector<string>ans;
    
    void helper(string digits,string output){
       int n=digits.length();
        
        if(n==0){
            ans.push_back(output);
            return ;
        }
        
        int a=digits[0]-'0'-2;
        string s=str[a];
        
        for(int i=0;i<s.length();i++){
            helper(digits.substr(1),output+s[i]);
        }
        
        
    }
   
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0){
            return ans;
        }
        
        helper(digits,"");
       
        return ans;
    }
};