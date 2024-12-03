class NumMatrix 
{
private:
    vector<vector<int>> pmatrix_;
    int c_(int i, int j)
    {
        return i < 0 || j < 0 ? 0 : pmatrix_[i][j];
    }

public:
    NumMatrix(vector<vector<int>>& matrix) 
    :pmatrix_(matrix)
    {
        for(int i = 0; i < pmatrix_.size(); ++i)
            for(int j = 0; j < pmatrix_[0].size(); ++j)
                pmatrix_[i][j]+= c_(i - 1, j) + c_(i, j - 1) - c_(i - 1, j - 1);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        return c_(row2, col2) + c_(row1 - 1, col1 - 1) - c_(row1 - 1, col2) - c_ (row2, col1 - 1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
