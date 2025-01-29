class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) 
    {
        if(p == 0)
            return 0;

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0;
        int high = nums[n - 1] - nums[0]; 
        while(low < high)
        {
            int mid = low + (high - low) / 2;
            int pairs = 0;
            for(int i = 1; i < n; ++i)
                if(nums[i] - nums[i - 1] <= mid)
                {
                    ++pairs;
                    ++i;
                }
            
            if(pairs >= p)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};
