class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + --k, nums.end(), greater<int>());
        return nums[k];
    }
};
