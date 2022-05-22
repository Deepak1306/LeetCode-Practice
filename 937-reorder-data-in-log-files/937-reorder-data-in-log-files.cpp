bool compare(string a, string b){
       int i=a.find(' ');
       int j=b.find(' ');
    
    if(a.substr(i+1)==b.substr(j+1)){
        return a<b;
    }
    
    return a.substr(i+1)<b.substr(j+1);
        
        
    }
    

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        
        vector<string>digits;
        vector<string>letter;
        
        for(int i=0;i<logs.size();i++){
            int j=logs[i].find(' ');
            
            if(logs[i][j+1]>='0' && logs[i][j+1]<='9'){
                digits.push_back(logs[i]);
            }else{
                letter.push_back(logs[i]);
            }
        }
        
        logs.clear();
        
        sort(letter.begin(),letter.end(),compare);
        logs.insert(logs.end(),letter.begin(),letter.end());                                   logs.insert(logs.end(),digits.begin(),digits.end());
        
        return logs;

        
    }
};