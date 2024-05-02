class Solution 
{
private:
    const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int, int>> q;
        const int MAX_VALUE = m * n;

        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(mat[i][j] == 0) 
                    q.emplace(i, j);
                else
                    mat[i][j] = MAX_VALUE;

        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            for(const auto [dx, dy] : directions)
            {
                auto nx = dx + x;
                auto ny = dy + y;
                if(0 <= nx && nx < m && 0 <= ny && ny < n  
                    && mat[x][y] + 1 < mat[nx][ny])
                {
                    mat[nx][ny] = mat[x][y] + 1;
                    q.emplace(nx, ny);
                }
            }
        }
       
        return mat;
    }
};
