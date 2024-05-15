class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int buy_prev = 0;
        int buy = INT_MIN;
        int sell_prev = 0; 
        int sell = 0; 

        for(auto p : prices)
        {
            buy_prev = buy;
            buy = max(sell_prev - p, buy);
            sell_prev = sell;
            sell = max(buy_prev + p, sell);
        }

        return sell;
    }
};
