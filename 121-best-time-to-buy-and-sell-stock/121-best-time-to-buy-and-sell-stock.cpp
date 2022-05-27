class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if( prices.empty() )
            return 0;
        int min_price_so_far = prices[0];
        int max_profit_so_far = 0;
        for( int i = 1; i < prices.size(); i++) {
            if( prices[i] < min_price_so_far)
                min_price_so_far = prices[i];
            if ( prices[i] - min_price_so_far >  max_profit_so_far)
                max_profit_so_far = prices[i] - min_price_so_far;
        }
        
        return max_profit_so_far;
            
    }
};