class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> shufled;
        auto it_x = nums.begin();
        auto it_y = nums.begin() + n;
        while(it_y != nums.end())
        {
            *it_x <<= 0x10; 
            *it_x |= *it_y;
            ++it_x;
            ++it_y;
        }

        it_x = nums.begin() + n - 1;
        it_y = nums.end() - 1;
        while(it_x >= nums.begin())
        {
            *it_y-- = *it_x & 0xFFFF;
            *it_y = *it_x >> 0x10;
            --it_x;
            --it_y;
        }
        
        return nums;
    }
};