class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones=0,twos=0;
        int common_bit_mask;
        for(int i=0;i<nums.size();i++)
            {
            /*
            twos = twos | (ones & nums[i]);
            ones = ones ^ nums[i];
            common_bit_mask = ~(ones & twos);
            ones &= common_bit_mask;
            twos &= common_bit_mask;*/
            ones=(ones^nums[i])&~twos;
            twos=(twos^nums[i])&~ones;
            }
        return ones;
    }
};