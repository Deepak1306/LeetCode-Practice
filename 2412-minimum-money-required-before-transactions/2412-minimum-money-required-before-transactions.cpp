class Solution {
public:
   static bool comp(vector<int> &a, vector<int> &b){
       return a[1]<b[1];
    }
    
    
    long long minimumMoney(vector<vector<int>>& transactions) {
        
        int n=transactions.size();
        sort(transactions.begin(),transactions.end(),comp);
        
        long long sum=0;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            arr[i]=transactions[i][1]-transactions[i][0];
            sum+=min(0,arr[i]);
        }
        
        if(sum<0){
            sum=-1 * sum;
        }
        
        long long ans=sum;
        long long count=0;
        
        for(int i=0;i<n;i++){
          if(transactions[i][0]>sum){
              count+=transactions[i][0]-sum;
              sum=transactions[i][0];
          }   
          
            sum+=min(0,arr[i]);
        }
        
        return count+ans;
    }
};