class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int y = 0; y < m; ++y)
            for(int x = 0; x < n; ++x)
            {
                if(y == 0 && x == 0) continue;
                if(y == 0) grid[y][x]+= grid[y][x - 1];
                else if(x == 0) grid[y][x]+= grid[y - 1][x];
                else grid[y][x]+= min(grid[y][x - 1], grid[y - 1][x]);
            }

        return grid[m - 1][n - 1];
    }
};
