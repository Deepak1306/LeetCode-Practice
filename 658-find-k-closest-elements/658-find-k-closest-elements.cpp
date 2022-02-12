class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
       
        int i=0;
        int j=arr.size()-1;
        while(j-i>=k){
            if(abs(arr[i]-x)>abs(arr[j]-x)){
                i++;
            }else{
                j--;
            }
        }
        
        vector<int>ans;
        
        for(int m=i ;m<=j;m++){
            ans.push_back(arr[m]);
        }
        
        return ans;    
        
    }
};