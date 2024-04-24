class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        array<int, 26> mp;

        for(char t : tasks)
            mp[t - 'A']++;

        for(auto count : mp)
            if(count) pq.push(count);

        int timer = 0;
        while(true)
        {
            queue<int> remaining;
            int cycle{n + 1};
            while(cycle && !pq.empty())
            {
                if(pq.top() > 1)
                    remaining.push(pq.top() - 1);

                pq.pop();
                ++timer;
                --cycle;
            }
            
            while(!remaining.empty())
            {
                pq.push(remaining.front());
                remaining.pop();
            }

            if(pq.empty()) break;

            timer+= cycle;
        }

        return timer;
    }
};
