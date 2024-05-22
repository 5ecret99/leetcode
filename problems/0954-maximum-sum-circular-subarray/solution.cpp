class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        int max_ = INT_MIN;
        int curr_max = 0;
        int min_ = INT_MAX;
        int curr_min = 0;
        int total_sum = 0;
        for(auto n : nums)
        {
            curr_max = max(n, curr_max + n);
            max_ = max(max_, curr_max);
            curr_min = min(n, curr_min + n);
            min_ = min(min_, curr_min);
            total_sum+= n;
        }

        return max_ > 0 ? max(max_, total_sum - min_) : max_; 
    }
};
