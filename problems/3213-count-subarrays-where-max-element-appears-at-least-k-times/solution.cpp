class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int max_num = *max_element(nums.begin(), nums.end());
        int count = 0;
        int l = 0;
        long long res = 0;

        for(int r = 0; r < n; ++r)
        {
            if(nums[r] == max_num)
                ++count;
            
            while(count >= k)
            {
                res+= n - r;
                if(nums[l++] == max_num)
                    --count;
            }
        }

        return res;
    }
};
