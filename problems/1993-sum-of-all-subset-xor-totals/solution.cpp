class Solution {
public:
    int subsetXORSum(vector<int>& nums)
    {
        int set_bits = 0;
        for(auto n : nums)
            set_bits|= n;
        
        return set_bits << nums.size() - 1;
    }
};
