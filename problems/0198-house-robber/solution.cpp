class Solution {
public:
    int rob(vector<int>& nums) {
       int prev_a = 0;
       int prev_b = 0;

       for(auto num : nums){
           auto dp = max(prev_a, prev_b + num);
           prev_b = prev_a;
           prev_a = dp;
       }

       return prev_a;
    }
};
