class Solution 
{
private:
    vector<vector<int>> res;
    vector<int> curr;
    int target_;
    int n;
    void combination(vector<int>& nums, int i = 0, int curr_sum = 0)
    {
        if(curr_sum == target_)
        {
            res.push_back(curr);
        }
        else if(i < n && curr_sum < target_)
        {
            curr.push_back(nums[i]);
            combination(nums, i, curr_sum + nums[i]);
            curr.pop_back();

            combination(nums, i + 1, curr_sum);
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) 
    {
        n = nums.size();
        target_ = target;
        combination(nums);
        return res;
    }
};
