class Solution {
private:
    int _m = 0;
    int _n = 0;
    vector<int> _dir = {0,1,0,-1,0};
    
    void bfs(queue<pair<int,int>> &q, vector<vector<bool>> &visited, vector<vector<int>>& heights)
    {
        static auto on_bounds = [this](int x, int y){
            return x >= 0 && x < _m && y >= 0 && y < _n;  
        };

        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            visited[x][y]=true;
            q.pop();

            for(int d = 0; d < _dir.size() -1; d++)
            {
                int xx = x + _dir[d];
                int yy = y + _dir[d + 1];

                if(on_bounds(xx,yy) && heights[x][y] <= heights[xx][yy] && !visited[xx][yy]) 
                    q.push({xx,yy});
            }
        }
    }
    
        
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        _m = heights.size();
        _n = heights[0].size();
 
        vector<vector<bool>> visitedp(_m, vector<bool>(_n, false));
        vector<vector<bool>> visitedq(_m, vector<bool>(_n, false));

        queue<pair<int,int>> pacific;
        queue<pair<int,int>> atlantic;
        
        for(int i = _m - 1; i >= 0; i--){
            pacific.push({i, 0});
            atlantic.push({i, _n - 1});
        }

        for(int i = _n - 1; i >= 0; i--){
            pacific.push({0, i});
            atlantic.push({_m - 1, i});
        }
        
        bfs(pacific, visitedp, heights);
        bfs(atlantic, visitedq, heights);
        
        vector<vector<int>> res{};
        for(int i = 0; i < _m; i++)
            for(int j = 0; j < _n; j++)
                if(visitedp[i][j] && visitedq[i][j])
                    res.push_back({i, j});
        
        return res;
    } 
};