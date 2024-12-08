class Solution 
{
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = nums[0];
        vector<int> suffix(n);
        suffix[n - 1] = nums[n - 1];
        for(int i = 1; i < n; ++i)
        {    
            prefix[i] = nums[i] + prefix[i - 1];
            suffix[n - 1 - i] = nums[n -i - 1] + suffix[n - i];
        }

        for(int i = 0; i < n; ++i)
            nums[i] =  (nums[i] * i) - prefix[i] + suffix[i] - (nums[i] * (n - 1 -i));

        return nums;
    }
};
