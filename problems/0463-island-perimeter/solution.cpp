class Solution {
private:
    int M = 0;
    int N = 0;
    int dfs(vector<vector<int>>& grid, int i, int j)
    {
        if(i < 0 || j < 0 || i == M 
            || j == N || grid[i][j] == 0)
        {
            return 1;
        }
        else if(grid[i][j] == 2)
        {
            return 0;
        }

        grid[i][j] = 2;
        return dfs(grid, i + 1, j) + dfs(grid, i, j + 1) 
            + dfs(grid, i - 1, j) + dfs(grid, i, j - 1);
    }
    
public:
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        M = grid.size();
        N = grid[0].size();
        for(int i = 0; i < M; ++i)
            for(int j = 0; j < N; ++j)
                if(grid[i][j] == 1) return dfs(grid, i , j);
        
        return -1;
    }
};
