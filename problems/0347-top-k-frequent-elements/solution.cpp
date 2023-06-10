class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(auto& num: nums)
            map[num]++;
        
        priority_queue<pair<int, int>> pq;
        for(auto& num: map)
            pq.push(make_pair(num.second, num.first));

        vector<int> res;
        while(k-- > 0 && !pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
