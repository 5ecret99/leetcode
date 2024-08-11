class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        int n = nums.size();
        for(int i = 0; i < n; ++i)
            if(nums[i] <= 0) nums[i] = n + 1;

        for(int num : nums)
        {
            num = abs(num) - 1;
            if(num >= 0 && num < n)
                nums[num] = - abs(nums[num]);
        }
        
        for(int i = 0; i < n; ++i)
            if(nums[i] >= 0)
                return i + 1;

        return n + 1;
    }
};
