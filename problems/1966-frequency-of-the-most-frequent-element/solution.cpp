class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        int r = nums.size() - 1;
        int l = nums.size() - 1;
        int curr_k = k;
        int res = 0;

        while(l >= 0)
        {
            int diff = nums[r] - nums[l];
            if(diff <= curr_k)
            {
                curr_k-= diff;
                res = max(res, r + 1 - l);
                --l;
            }
            else
            {
                int val = nums[r];
                while(--r >= 0 && nums[r] == val);
                if(r <= res) return res;
                l = r;
                curr_k = k;
            }
        }


       return res; 
    }
};
