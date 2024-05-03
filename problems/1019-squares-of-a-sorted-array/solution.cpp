class Solution 
{
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        int l = 0;
        vector<int> squared(nums.size());
        while(l < nums.size() && nums[l] < 0) l++;

        int i = 0;
        int r = l;
        --l;

        while(i < squared.size())
            squared[i++] = l < 0 ? nums[r] * nums[r++]
                : r >= nums.size() ? nums[l] * nums[l--]
                : -nums[l] < nums[r] ? nums[l] * nums[l--] 
                : nums[r] * nums[r++];

        return squared;
    }
};
