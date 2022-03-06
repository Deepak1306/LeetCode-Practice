class Solution {
public:
    int countOrders(int n) {
        long long count=1;
        int mod=1e9+7;
        for(int i=2;i<=n;i++){
            count=(count*i*(2*i-1))%mod;
        }
        
        return count%mod;
    }
};