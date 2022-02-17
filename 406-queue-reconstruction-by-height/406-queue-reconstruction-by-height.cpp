class Solution {
public:
    static bool comparator(vector<int>&a1,vector<int>&a2){
        if(a1[0]!=a2[0]){
            return a1[0]>a2[0];
        }
        else{
            return a2[1]>a1[1];
        }
        
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
      
        sort(people.begin(),people.end(),comparator);
        vector<vector<int>> ans;
        
        for(int i=0;i<people.size();i++){
            ans.insert(ans.begin()+people[i][1],{people[i][0],people[i][1]});
        }
        
        return ans;
    }
};