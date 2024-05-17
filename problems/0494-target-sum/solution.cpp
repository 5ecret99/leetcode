class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int acc = accumulate(nums.begin(), nums.end(), 0);
        int new_target = (acc + target) / 2;

        if(acc < target || (acc + target) & 1 || new_target < 0)
            return 0;
    
        vector<int> dp(new_target + 1, 0);
        dp[0] = 1;
        for(auto n : nums)
            for(int i = new_target; i >= n; --i)
                dp[i]+= dp[i - n];

        return dp[new_target];
    }
};
