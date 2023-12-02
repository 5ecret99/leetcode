class Solution {
private:
    struct pair_comp{
        bool operator()(const pair<int, int>& a, const pair<int, int>& b){
            return a.first > b.first; 
        }
    };
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> mp;
        for(int i = 0; i < times.size(); ++i)
            mp[times[i][0]].emplace_back(times[i][1], times[i][2]);

        vector<int> distances(n + 1, INT_MAX);
        distances[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, pair_comp> min_heap;
        min_heap.emplace(0,k);

        while(!min_heap.empty()){
            auto [weight, node] = min_heap.top();
            min_heap.pop();
            for(auto [nnode, nweight] : mp[node])
                if(weight + nweight < distances[nnode]){
                    distances[nnode] = weight + nweight;
                    min_heap.emplace(distances[nnode], nnode);
                }
        }

        int max_dist{0};
        for(auto it = distances.begin() + 1; it != distances.end(); ++it){
            if(*it == INT_MAX) return -1;
            max_dist = max(max_dist, *it);
        }
        
        return max_dist;
    }
};