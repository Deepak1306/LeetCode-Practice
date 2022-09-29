class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
         int n=arr.size();
        int i=0;
        int j=n-1;
        
        while(j-i>=k){
            if(abs(arr[i]-x)>abs(arr[j]-x)){
                i++;
            }else{
                j--;
            }
        }
        vector<int>ans;
        while(i<=j){
             ans.push_back(arr[i]);
             i++;
        }
        return ans;
        
    }
};