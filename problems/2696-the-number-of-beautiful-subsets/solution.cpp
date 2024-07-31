class Solution {
private:
    unordered_map<int, int> count_;
    int n_;
    int k_;
    int helper(const vector<int>& nums, int ind = 0)
    {
        if(ind == n_) return 1;

        int res = helper(nums, ind + 1);

        if(!(count_.contains(nums[ind] - k_) || count_.contains(nums[ind] + k_)))
        {
            count_[nums[ind]]++;
            res+= helper(nums, ind + 1);
            count_[nums[ind]]--;
            if(!count_[nums[ind]])
                count_.erase(nums[ind]);
        }

        return res;
    }

public:
    int beautifulSubsets(vector<int>& nums, int k) 
    {
        k_ = k;
        n_ = nums.size();
        return helper(nums) - 1;
    }
};
