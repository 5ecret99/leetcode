class Solution {
private:
    bool helper(vector<vector<char>>& board, string word, int i, int j, int pos = 0){
        if(pos == word.size()) return true;
        if ((i<0) || (i >= board.size()) 
        || (j <0) || (j >= board[i].size())) return false;
        
        auto c = board[i][j];
        if(c == word[pos]){
            board[i][j] = '#';
            pos++;
            if (helper(board, word, i - 1, j, pos)
            || helper(board, word, i+1, j, pos)
            || helper(board, word, i, j-1, pos)
            || helper(board, word, i, j+1, pos)) return true;
            board[i][j] = c;
        }

        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(!board.size()) return false;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j<board[i].size(); j++){
                if( helper(board, word, i, j)) return true;
            }
        }
        return false;
    }
};