class Solution {
private:
    int helper(vector<int> nums, int start, int end){
        int prev_a = 0;
        int prev_b = 0;
        
        for(int i = start; i < end; i++){
            auto dp = max(prev_a, prev_b + nums[i]);
            prev_b = prev_a;
            prev_a = dp;
        }

        return prev_a;
    }

public:
    int rob(vector<int>& nums){
        if(!nums.size()) return 0;
        else if (nums.size() == 1) return nums[0];

        return max(helper(nums, 0, nums.size() - 1), helper(nums, 1, nums.size()));
    }
};