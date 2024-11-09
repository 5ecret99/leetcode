class Solution 
{
private:
    int max_local(vector<vector<int>>& grid, int y, int x)
    {
        int num = 0;
        for(int i = y - 1; i <= y + 1; ++i)
            for(int j = x - 1; j <= x + 1; ++j)
                num = max(num, grid[i][j]);
        
        return num;
    }

public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) 
    {
        int n  = grid.size();
        vector<vector<int>> maxLocal(n - 2, vector<int>(n - 2));
        for(int i = 0; i < n - 2; ++i)
            for(int j = 0; j < n - 2; ++j)
                maxLocal[i][j] = max_local(grid, i + 1, j + 1);
        
        return maxLocal;
    }
};
