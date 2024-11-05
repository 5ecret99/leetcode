class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) 
    {
        int r = wall.size();
        unordered_map<int, int> not_crossed;
        for(int i = 0; i < r; ++i)
        {
            int curr = 0;
            for(int j = 0; j + 1 < wall[i].size(); ++j)
            {
                curr+=wall[i][j];
                not_crossed[curr]++;
            }
        }

        int max_not_crossed = 0;
        for(auto [_, cnt] : not_crossed)
            max_not_crossed = max(max_not_crossed, cnt);
        
        return r - max_not_crossed;
    }
};
