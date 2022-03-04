class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
        double water[101][101]={0.0};
        water[0][0]=poured;
        
        
        for(int i=0;i<100;i++){    
            for(int j=0;j<=i;j++){
                if(water[i][j]>1){
                    water[i+1][j]+=(water[i][j]-1)/2.0;
                    water[i+1][j+1]+=(water[i][j]-1)/2.0;
                    water[i][j]=1;
                }
            }
        }
        
        return water[query_row][query_glass];
        
    }
};