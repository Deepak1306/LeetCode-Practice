class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n=data.size();
        
        int count=0;
        int c=0;
        for(int i=0;i<n;i++){
            string s=bitset<8>(data[i]).to_string();
            cout<<s<<" ";
            
            if(s[0]=='1' && s[1]=='0'){
                if(count==0){
                    return false;
                }
                c++;
            }else{
                if((count>4) || (count!=0 && c!=count-1)){
                    return false;
                }
                count=0;
                c=0;
                
                    int j=0;
                    while(s[j]!='0' && j<s.length()){
                       count++;
                        j++;
                    }
                
            } 
            
        }
        
        if(count>4){
            return false;
        }
        
        if(count!=0 && c!=count-1){
            return false;
        }
        
        
        
        return true;
        
    }
};