class Solution {
public:
    int dp[301][11];
    
    int solve(vector<int> &arr, int d, int i){
        if(i==arr.size()){
            if(d==0){
                return 0;
            }else{
                return 1e5;
            }
        }else if(d==0){
            return 1e5;
        }
        else if(dp[i][d]!=-1){
            return dp[i][d];
        }
        int ans=INT_MAX;
        int a=INT_MIN;
        for(int k=i;k<arr.size();k++){
            
            if(arr[k]>a){
                a=arr[k];
            }
            
            ans=min(ans,a+solve(arr,d-1,k+1));
            
        }
        
        return dp[i][d]=ans;
        
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        
        memset(dp,-1,sizeof(dp));
        
        
        
        if(n<d){
            return -1;
        }
        
        return solve(jobDifficulty,d,0);
        
    }
};