class Solution {
public:
    int minOperations(vector<int>& nums, int x) 
    {
        int n = nums.size();
        int target = accumulate(nums.begin(), nums.end(), -x);
        if(target == 0)
            return n;

        int curr = 0;
        int max_len = 0;
        int l = 0;
        for(int r = 0; r < n; ++r)
        {
            curr+= nums[r];
            while(l <= r && curr > target)
                curr-= nums[l++];
            
            if(target == curr)
                max_len = max(max_len, r - l + 1);
        }

        return max_len == 0 ? -1 : n  - max_len;
    }
};
