class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq{stones.begin(), stones.end()};
        while(pq.size() > 1)
        {
            auto new_stone = pq.top();
            pq.pop();
            new_stone-=pq.top();
            pq.pop();
            if(new_stone)
                pq.push(new_stone);
        }

        return pq.empty() ? 0 : pq.top();
    }
};
