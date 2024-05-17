class Solution {
private:
    int n;
    vector<vector<int>> res;
    void helper(vector<int> nums, int i = 0)
    {
        if(i == n - 1)
        {
            res.push_back(nums);
            return;
        }

        helper(nums, i + 1);
        for(int j = i + 1; j < n; ++j)
        {
            if(nums[i] == nums[j]) continue;
            swap(nums[i], nums[j]);
            helper(nums, i + 1);
        }

    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        n = nums.size();
        helper(nums);
        return res;
    }
};
