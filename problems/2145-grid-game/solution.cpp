class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) 
    {
        long up = accumulate(++grid[0].begin(), grid[0].end(), 0l);
        long down = 0;
        long res = up;
        for(int i = 1; i < grid[0].size(); ++i)
        {
            up-= grid[0][i];
            down+= grid[1][i - 1];
            res = min(res, max(up, down));
        }
        
        return res;
    }
};
