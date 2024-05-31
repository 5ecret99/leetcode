class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int total = 0;
        int len = n + 1;
        while(r < n)
        {
            total+= nums[r++];
            while(total >= target)
            {
                len = min(len, r - l);
                total-= nums[l++];
            }
        }

        return len == n + 1 ? 0 : len; 
    }
};
