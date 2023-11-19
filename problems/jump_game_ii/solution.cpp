class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        auto left = nums.begin();
        auto right = nums.begin();
        while(right < nums.end() - 1){
            long furthest = 0;
            for(auto it = left; it <= right; ++it)
                furthest = max(furthest, distance(nums.begin(), it + *it));

            left = right + 1;
            right = nums.begin() + furthest;
            ++jumps;
        }

        return jumps;
    }
};
