class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum{INT_MIN};
        int curr{0};
        for(int i = 0; i < nums.size(); i++){
            curr = max(nums[i], curr + nums[i]);
            max_sum = max(max_sum, curr); 
        }

        return max_sum;
    }
};
