class Solution {
private:
    bool helper(vector<vector<char>>& grid,int i, int j){
        if(i < 0 || i >= grid.size() 
        || j < 0 || j >= grid[i].size()
        || grid[i][j] != '1') return false;
        
        grid[i][j] = '#';
        helper(grid, i - 1, j);
        helper(grid, i + 1, j);
        helper(grid, i, j - 1);
        helper(grid, i, j + 1);
        return true;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(helper(grid, i, j)) islands++;
            }
        }

        return islands;
    }
};