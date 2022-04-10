class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int>ans;
        
        for(int i=0;i<ops.size();i++){
            if(ops[i]=="C"){
                if(ans.size()==0){
                    continue;
                }
                
                ans.pop_back();
                
            }else if(ops[i]=="D"){
                int c=ans[ans.size()-1];
                c*=2;
                ans.push_back(c);
                
            }else if(ops[i]=="+"){
                int a=ans[ans.size()-1];
                int b=ans[ans.size()-2];
                
                ans.push_back(a+b);
                
            }else{
                stringstream geek(ops[i]);
                int c=0;
                
                geek>>c;
                ans.push_back(c);
            }
        }
        
        int sum=0;
        
        for(int i=0;i<ans.size();i++){
        sum+=ans[i];    
        }
        
        return sum;
    }
};