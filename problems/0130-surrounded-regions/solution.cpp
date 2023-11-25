class Solution {
private:
    int xend;
    int yend;
    void dfs(vector<vector<char>>& board, int x, int y){
        if( x < 0 || y < 0 || x >= xend || y >= yend || board[x][y] != 'O') 
            return;
        
        board[x][y] = 'G';
        dfs(board, x + 1, y); 
        dfs(board, x, y + 1); 
        dfs(board, x - 1, y); 
        dfs(board, x, y - 1);
    }
    
public:
    void solve(vector<vector<char>>& board) {
        int x;
        int y;
        xend = board.size();
        yend = board[0].size();
        for(y = 0; y < yend; ++y){
            dfs(board, 0, y);
            dfs(board, xend - 1, y);
        }

        for(x = 0; x < xend; ++x){
            dfs(board, x, 0);
            dfs(board, x, yend - 1);
        }

        for(x = 0; x < xend; ++x)
            for(y = 0; y < yend; ++y)
                board[x][y] = board[x][y] == 'G' ? 'O' : 'X'; 
    }
};
