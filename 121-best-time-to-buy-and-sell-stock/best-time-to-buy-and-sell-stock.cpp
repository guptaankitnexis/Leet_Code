class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int buying_Price = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); ++i) {
            // Update the minimum price so far using the min function
            buying_Price = min(buying_Price, prices[i]);
            // Calculate profit if selling at current price and update maxProfit
            maxProfit = max(maxProfit, prices[i] - buying_Price);
        }

        return maxProfit;
    }
};