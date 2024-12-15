class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) 
    {
        priority_queue<int> pq;
        for(int i = 1; i < heights.size(); ++i)
        {
            int diff = heights[i] - heights[i - 1];
            if(diff <= 0)
                continue;

            if(bricks >= diff)
            {
                bricks-= diff;
                pq.push(diff);
            }
            else if(ladders > 0)
            {
                --ladders;
                bricks-= diff;
                pq.push(diff);
                bricks+= pq.top();
                pq.pop();
            }
            else
                return --i;
        }

        return heights.size() - 1;
    }
};
