class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int right = nums.size() - 1;
        int left = 0;
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            bool is_odd = mid & 1;
            if((is_odd && nums[mid] == nums[mid - 1]) 
                || (!is_odd && nums[mid] == nums[mid + 1]))
                left = mid + 1;
            else
                right = mid;
        }

        return nums[left];
    }
};
