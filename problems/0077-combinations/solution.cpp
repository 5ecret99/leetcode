class Solution {
private:
    vector<vector<int>> res;
    vector<int> curr;
    int n_;
    int k_;
    void backtrack(int ind = 1)
    {
        if(curr.size() == k_)
        {
            res.push_back(curr);
            return;
        }

        for(int i = ind; i <= n_ + 1 - k_ + curr.size(); ++i)
        {
            curr.push_back(i);
            backtrack(i + 1);
            curr.pop_back();
        }
        
    }
public:
    vector<vector<int>> combine(int n, int k) 
    {
        n_ = n;
        k_ = k;
        backtrack();
        return res; 
    }
};
