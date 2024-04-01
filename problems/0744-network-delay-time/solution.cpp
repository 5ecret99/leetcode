class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        using edge = pair<int, int>; //(weight, node)

        vector<edge> adj[n + 1];
        for(const auto& t : times)
            adj[t[0]].emplace_back(t[2], t[1]);
        
        priority_queue<edge, vector<edge>, greater<edge>> pq;
        pq.emplace(0, k);

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        while(!pq.empty())
        {
            auto [time, node] = pq.top();
            pq.pop();

            for(const auto& [ctime, cnode] : adj[node])
                if(time + ctime < dist[cnode])
                {
                    dist[cnode] = time + ctime;
                    pq.emplace(dist[cnode], cnode);
                }
        }

        auto mx = *max_element(dist.begin() + 1, dist.end());

        return mx < INT_MAX ? mx : -1;
    }
};
