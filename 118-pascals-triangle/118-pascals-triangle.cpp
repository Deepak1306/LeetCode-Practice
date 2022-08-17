class Solution {
public:
    
    
    
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans(numRows);
        if(numRows==0){
            return ans;
        }else if(numRows==1){
            ans[0]={1};
            return ans;
        }
        
        ans[0]={1};
        
        ans[1]={1,1};
        
        for(int i=2;i<numRows;i++){
            vector<int>a;
            a.push_back(1);
            for(int j=0;j<ans[i-1].size()-1;j++){
                a.push_back(ans[i-1][j]+ans[i-1][j+1]);
            }
            a.push_back(1);
            ans[i]=a;
        }
        
        return ans;
    }
};