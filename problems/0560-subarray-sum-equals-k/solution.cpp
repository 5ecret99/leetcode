class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int res = 0;
        unordered_map<int, int> prefix_sum;
        prefix_sum[sum] = 1;
        for(auto num : nums)
        {
            sum+= num;
            if(prefix_sum.contains(sum - k))
                res+= prefix_sum[sum - k];
            
            prefix_sum[sum]++;
        }

        return res;
    }
};
