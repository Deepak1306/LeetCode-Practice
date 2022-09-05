class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        map<char,int>m;
        
        int i=0;
        int j=0;
        int ans=INT_MIN;
        bool check=true;
        
        while(i<n){
            int len=i-j+1;
            
            if(check){
            m[s[i]]++;                
            }
            int maxCount=INT_MIN;
            
            for(auto it:m){
                maxCount=max(maxCount,it.second);
            }
            
            // cout<<j<<" "<<i<<" "<<m['A']<<" "<<m['B']<<endl;
            
            
            int count=len-maxCount;
            if(count<=k){
                ans=max(ans,len);
                i++;
                check=true;
            }else{
                m[s[j]]--;
                j++;
                check=false;
            }
            
            
        }
        
        return ans;
        
    }
};