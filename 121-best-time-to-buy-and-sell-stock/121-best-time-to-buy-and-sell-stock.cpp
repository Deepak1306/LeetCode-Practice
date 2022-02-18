class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxProfit=0;
        int buy=prices[0];
        
        for(int i=1;i<prices.size();i++){
            if(prices[i]<buy){
                buy=prices[i];
            }else{
                int sell=prices[i];
                int count=sell-buy;
                
                maxProfit=max(count,maxProfit);
            }
        }
        return maxProfit;
    }
};