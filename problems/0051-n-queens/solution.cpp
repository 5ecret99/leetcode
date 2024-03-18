class Solution {
private:
    int qn;
    vector<bool> col;
    vector<bool> diag1;
    vector<bool> diag2;
    vector<string> curr;
    vector<vector<string>> res;

    void nqueens()
    {
        if(curr.size() == qn)
        {
            res.push_back(curr);
            return;
        }

        int y = curr.size();
        auto queen_str = [qn = qn](int x){
            string qstr(qn, '.');
            qstr[x] = 'Q';
            return qstr;
        };

        for(int x = 0; x < qn; ++x)
        {
            if(col[x] || diag1[x + y] || diag2[x - y + qn - 1])
            {
                continue;
            }

            col[x] = diag1[x + y] = diag2[x - y + qn - 1] = true;
            curr.push_back(queen_str(x));

            nqueens();

            col[x] = diag1[x + y] = diag2[x - y + qn - 1] = false;
            curr.pop_back();
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) 
    {
        if(n == 1) 
        {
            return {{"Q"}};
        }

        qn = n;
        col = vector<bool>(n, false);
        diag1 = vector<bool>(2 * (n - 1), false);
        diag2 = vector<bool>(2 * (n - 1), false);
        nqueens();
        return res;
    }
};
