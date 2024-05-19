class Solution 
{
private:
    vector<int> edges_;
    int edge_len_;
    int n_;
    bool bt(vector<int>& matches, int ind = 0)
    {
        if(ind == n_) return true;
        for(int i = 0; i < edges_.size(); ++i)
        {
            if(edges_[i] + matches[ind] <= edge_len_) 
            {
                edges_[i]+= matches[ind];
                if(bt(matches, ind + 1))
                    return true;
                
                edges_[i]-= matches[ind];
            }
        }

        return false;
    }
public:
    bool makesquare(vector<int>& matches) 
    {
        int sum = accumulate(matches.begin(), matches.end(), 0);
        if(sum % 4) return false;
        sort(matches.begin(), matches.end(), greater<int>());
        edges_.resize(4, 0);
        edge_len_ = sum / 4;
        n_ = matches.size();
        return bt(matches);
    }
};
