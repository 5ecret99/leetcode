class Solution {
    vector<vector<int>> combos;
    vector<int> curr_combo;
    void helper(const vector<int>& nums, int target, int sum = 0, int index = 0)
    {
        if(sum > target) return;
        if(sum == target)
        {
            combos.push_back(curr_combo);
            return;
        }

        for(int i = index; i < nums.size(); ++i)
        {
            if(i != index && nums[i] == nums[i - 1]) continue;
            sum+=nums[i];
            curr_combo.push_back(nums[i]);
            helper(nums, target, sum, i + 1);
            sum-=nums[i];
            curr_combo.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        helper(candidates, target);
        return combos;
    }
};