class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res{};
        for(auto it = nums.begin(); it != nums.end(); it++){
            auto lb = lower_bound(res.begin(), res.end(), *it);
            if(lb == res.end())
                res.push_back(*it);
            else
                *lb = *it;
        }

        return res.size();
    }
};