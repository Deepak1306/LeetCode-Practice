class NumMatrix {
public:
    vector<vector<int>>arr;
    
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        arr.resize(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0){
                    arr[i][j]=matrix[i][j];
                }
                else if(i==0){
                    arr[i][j]=arr[i][j-1]+matrix[i][j];
                }else if(j==0){
                    arr[i][j]=arr[i-1][j]+matrix[i][j];
                }else{
                    arr[i][j]=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1]+matrix[i][j];
                }
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int a=arr[row2][col2];
        int b=0;
        int c=0;
        int d=0;
        
        if(col1>0){
            b=arr[row2][col1-1];
        }
        
        if(row1>0){
            c=arr[row1-1][col2];
        }
        
        if(row1>0 && col1>0){
            d=arr[row1-1][col1-1];
        }
        
        
        return a-b-c+d;
        
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */