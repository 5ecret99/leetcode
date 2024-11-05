class Solution {
public:
    vector<int> getRow(int r) 
    {
        vector<int> res(r + 1, 1);
        for(int i = 1; i <= r; ++i)
            res[i] = static_cast<unsigned long>(res[i - 1]) * (r - i + 1) / i;

        return res;
    }
};
