class Solution 
{
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;

        for(int i = 1; i <= target; ++i)
            for(auto n : nums)
                if(i - n >= 0)
                    dp[i]+= dp[i - n];

        return dp[target];
    }
};
