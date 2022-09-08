class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        
        if(sum%2!=0){
            return 0;
        }
        
        sum=sum/2;
        
        bool dp[n+1][sum+1];
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(j==0){
                    dp[i][j]=true;
                }else if(i==0){
                    dp[i][j]=false;
                }else{
                    dp[i][j]=false;
                    
                    if(arr[i-1]<=j){
                        dp[i][j]=dp[i-1][j-arr[i-1]];
                    }
                    
                    dp[i][j]=dp[i][j] || dp[i-1][j];
                }
            }
        }
        
        
        return dp[n][sum];
        
    }
};