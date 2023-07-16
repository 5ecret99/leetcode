class Solution {
private:
    int remaining_nodes = 0;
    int helper(vector<vector<int>>& grid,int i, int j){

        if(i < 0 || i >= grid.size() 
        || j < 0 || j >= grid[i].size() || grid[i][j] == -1) return 0;

        bool is_zero = !grid[i][j];
        remaining_nodes--;
        grid[i][j] = -1;//visited
        if(is_zero) return 0;

        return 1 + helper(grid, i - 1, j) + helper(grid, i + 1, j)
        + helper(grid, i, j - 1) + helper(grid, i, j + 1);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        remaining_nodes = grid.size() * grid[0].size();
        int max_land_size = 0;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                max_land_size = max(helper(grid, i, j), max_land_size);
                if(remaining_nodes <= max_land_size) return max_land_size;

            }
        }

        return max_land_size;
    }
};