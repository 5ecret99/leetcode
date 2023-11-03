class Solution {
private:
    vector<vector<int>> subsets;
    vector<int> curr_subset;
    void helper(const vector<int>& nums, int index = 0)
    {
        subsets.push_back(curr_subset);
        for(int i = index; i < nums.size(); ++i)
        {
            if(i != index && nums[i] == nums[i - 1])
                continue;
            
            curr_subset.push_back(nums[i]);
            helper(nums, i + 1);
            curr_subset.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        helper(nums);
        return subsets;
    }
};