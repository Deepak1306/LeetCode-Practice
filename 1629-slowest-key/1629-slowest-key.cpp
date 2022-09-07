class Solution {
public:
    char slowestKey(vector<int>& arr, string s) {
        int n=arr.size();      
        vector<int>a;
        a.insert(a.end(),arr.begin(),arr.end());
        for(int i=1;i<n;i++){
            a[i]=arr[i]-arr[i-1];
        }
        
        int ans=INT_MIN;
        char c='~';
        for(int i=0;i<n;i++){
            if(a[i]>ans){
                c=s[i];
                ans=a[i];
            }else if(a[i]==ans){
                c=max(s[i]-'a',c-'a')+'a';
            }
        }
        
        
        return c;
        
    }
};