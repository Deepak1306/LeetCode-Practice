class Solution {
public:
    bool isPalindrome(string s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
    
    void solve(string s,int i,int j, vector<vector<string>>& ans, vector<string>a){
        string str="";
        if(i==j){
            str+=s[i];
            a.push_back(str);
            ans.push_back(a);
            a.pop_back();
            return ;
        }
        else if(isPalindrome(s,i,j)){
            str=s.substr(i,j-i+1);
            a.push_back(str);
            ans.push_back(a);
            a.pop_back();
        }
        
        
        for(int k=i;k<j;k++){
            if(isPalindrome(s,i,k)){
                str=s.substr(i,k-i+1);
                a.push_back(str);
                solve(s,k+1,j,ans,a);
                a.pop_back();
            }
        }
        
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>a;
        
        solve(s,0,s.length()-1,ans,a);
        
        return ans;
    }
};