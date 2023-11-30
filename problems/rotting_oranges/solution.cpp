class Solution {
private:
    int xend{0};
    int yend{0};
    long bfs(vector<vector<int>>& grid, int x, int y){
        if(x < 0 || y < 0 || x >= xend || y >= yend || grid[x][y] == 0) return INT_MAX; 
        if(grid[x][y] == 2) return 0;

        grid[x][y] = 0;
        long min_dist = 1 + min(min(bfs(grid, x + 1, y), bfs(grid, x, y + 1)),
                                min(bfs(grid, x - 1, y), bfs(grid, x, y - 1)));
        grid[x][y] = 1;

        return min_dist;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        xend = grid.size();
        yend = grid[0].size();
        long max_dist{0};
        for(int x = 0; x < xend; ++x)
            for(int y = 0; y < yend; ++y)
                if(grid[x][y] == 1)
                {
                    max_dist = max(max_dist, bfs(grid, x, y));
                    if(max_dist >= INT_MAX) return -1;
                }

        return max_dist;
    }
};