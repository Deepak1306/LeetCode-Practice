class Solution {
public:
    int countBinarySubstrings(string s) {
    
        int n=s.size();
        
        int count=0;
        int prev=0;
        int curr=1;
        
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                curr++;
            }else{
                count+=min(curr,prev);
                prev=curr;
                curr=1;
            }
        }
        count+=min(prev,curr);
        
        return count;
        
    }
};