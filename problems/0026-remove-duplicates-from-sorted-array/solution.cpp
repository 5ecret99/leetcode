class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto ind = 0;
        for(auto n : nums)
            if(ind < 1 || n > nums[ind - 1])
                nums[ind++] = n;

        return ind;
    }
};
