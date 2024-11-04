class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) 
    {
        int res = 0;
        unordered_map<int, int> counter;

        for(auto n : nums)
            res += counter[n]++;

        return res;
    }
};
