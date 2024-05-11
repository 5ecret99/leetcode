class Solution {
    vector<int> prefix_;
    int n_;
    int total_weight_;
public:
    Solution(vector<int>& w) 
    {
        n_ = w.size();
        prefix_.resize(n_);
        prefix_[0] = w[0];
        for(int i = 1; i < n_; ++i)
            prefix_[i] = prefix_[i - 1] + w[i];

        total_weight_ = prefix_[n_ - 1];
    }
    
    int pickIndex() 
    {
        int target = rand() % total_weight_;
        int l = 0;
        int r = n_ - 1;
        while(l < r)
        {
            int m = l + (r - l) / 2;
            if(prefix_[m] > target)
                r = m;
            else
                l = m + 1;
        }

        return l;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
