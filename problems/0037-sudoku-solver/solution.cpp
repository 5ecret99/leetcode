class Solution {
public:
    bool is_valid(vector<vector<char>>& board, int row, int col, char ch){
        for(int i = 0; i < board.size(); i++){
            if(board[row][i] == ch || board[i][col] == ch 
            || board[row/3*3 + i/3][col/3*3 + i%3] == ch){
                return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board, int a = 0){
        for(int i = a; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] != '.') continue;
                for(char ch = '1'; ch <= '9'; ch++){
                    
                    if(is_valid(board, i, j, ch)){
                        board[i][j] = ch;
                        if(solve(board,i)){
                            return true;
                        }
                    }

                    board[i][j] = '.';
                }
                return false;
            }

        }

        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
