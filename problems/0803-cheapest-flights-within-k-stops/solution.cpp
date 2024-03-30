class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<pair<int, int>> adj[n]; // (src, dst, price)
        for(auto& flight : flights)
            adj[flight[0]].emplace_back(flight[1], flight[2]);
        
        vector<long int> prices(n, INT_MAX);
        prices[src] = 0;
        queue<tuple<int, int, int>> q; // (city, price, stops)
        q.emplace(src, 0, -1);

        while(!q.empty())
        {
            auto [city, price, stops] = q.front();
            q.pop();
            if(stops >= k) continue;

            for(const auto& [dcity, dprice] : adj[city])
            {
                auto total_price = price + dprice;
                if(total_price < prices[dcity])
                {
                    prices[dcity] = total_price;
                    q.emplace(dcity, total_price, stops + 1);
                }
            }
        }


        return prices[dst] >= INT_MAX ? -1 : prices[dst];
    }

};
