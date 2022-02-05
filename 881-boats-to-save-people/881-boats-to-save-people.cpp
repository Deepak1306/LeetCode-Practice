class Solution {
public:
    int numRescueBoats(vector<int>& arr, int limit) {
        sort(arr.begin(),arr.end());
        
        int count=0;
        int i=0;
        int j=arr.size()-1;
        
        while(i<j){
            if(arr[i]+arr[j]<=limit){
                i++;
                j--;
                count++;
            }else{
                j--;
                count++;
            }
            
        }
        if(i>j){
            return count;
        }else{
             return count+1;
        }
         
       
    }
};