class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        int target = accumulate(nums.begin(), nums.end(), 0);//calculating overall sum
        if(target & 1) return false;//checking if its odd 
        target>>= 1;//dividing by 2
        bitset<10000> bits {1};// (max_num * max_len) / 2 = 1000
        for(auto n : nums)
            bits|= bits << n;//adding n to previous sums

        return bits[target];
    }
};
