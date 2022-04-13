class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n,0));
        
        int up=0;
        int down=n-1;
        int left=0;
        int right=n-1;
        
        int k=1;
        
        while(k<=n*n){
            int i=left;
            
            while(i<=right){
                ans[up][i]=k;
                k++;
                i++;
            }
            up++;
            
            i=up;
            while(i<=down){
                ans[i][right]=k;
                k++;
                i++;
                
            }
            right--;
            
            i=right;
            
            while(i>=left){
                ans[down][i]=k;
                k++;
                i--;
            }
            down--;
            
            i=down;
            while(i>=up){
                ans[i][left]=k;
                k++;
                i--;
            }
            left++;
            
        }
        
        
        return ans;
        
    }
};