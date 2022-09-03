class Solution {
public:
    
    void solve(int a,int n,int k, set<int>&s){
        if(n==0){
            s.insert(a);
            return ;
        }
        
        for(int i=0;i<=9;i++){
            int c=a%10;
            if(a==0 && i!=0){
                solve(i,n-1,k,s);
            }else if(abs(c-i)==k && a!=0){
                solve(a*10+i,n-1,k,s);
            }
        }
        
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans;
        set<int>s;
        solve(0,n,k,s);
        
        for(auto it:s){
            ans.push_back(it);
        }
        return ans;
    }
};