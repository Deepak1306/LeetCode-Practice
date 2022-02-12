class Solution {
public:
    bool rotateString(string s, string goal) {
        
        unordered_map<string,int>map;
        int n=s.length();
        map[goal]=1;
        int i=0;
        
        while(i<n){
            
            if(map[s]!=0){
                return true;
            }
            int temp=s[0];
            for(int i=0;i<n-1;i++){
                s[i]=s[i+1];
            }
            s[n-1]=temp;
            i++;
        }
        
        return false;
        
    }
};