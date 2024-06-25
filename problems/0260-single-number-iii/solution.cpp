class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        long int init_xor{0};
        for(auto n : nums) init_xor^= n;

        int mask = init_xor & -init_xor;//getting rightmost bit;
        int first_num = 0;

        for(auto n : nums) 
            if(n & mask)
                first_num^= n;
 
        return {first_num, static_cast<int>(init_xor ^ first_num)};
    }
};
