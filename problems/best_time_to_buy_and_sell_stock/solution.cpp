class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_price = prices[0];

        for(auto it = prices.begin() + 1; it != prices.end(); it++){
            min_price = min(min_price, *it);
            max_profit = max(max_profit, *it - min_price);
        }

        return max_profit;
    }
};