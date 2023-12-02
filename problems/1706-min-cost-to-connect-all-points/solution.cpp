class Solution {
private:
    struct pair_comp{
        bool operator()(const pair<int, int>& a, const pair<int, int>& b){
            return a.first > b.first; 
        }
    };

    int manhattan(const vector<int>& pointa, const vector<int>& pointb){
        return abs(pointb[0] - pointa[0]) + abs(pointb[1] - pointa[1]);
    }
    
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<bool> visited(points.size(), false);
        vector<int> distances(points.size(), INT_MAX);
        distances[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, pair_comp> min_heap;
        min_heap.emplace(0,0);
        int cost{0};
        while(!min_heap.empty()){
            auto [dist, p] = min_heap.top();
            min_heap.pop();
            if(visited[p] || distances[p] < dist) continue;
            visited[p] = true;
            cost+= dist;

            for(int i = 1; i < points.size(); ++i){
                if(visited[i]) continue;
                auto new_dist = manhattan(points[p], points[i]);
                if(new_dist < distances[i]){
                    distances[i] = new_dist;
                    min_heap.emplace(new_dist, i);
                }
            }
        }

        return cost;
    }
};
