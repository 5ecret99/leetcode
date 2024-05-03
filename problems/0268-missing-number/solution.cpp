class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        unsigned long long res = nums.size();
        for(int i = 0; i < nums.size(); ++i)
        {
            res^= i;
            res^= nums[i];
        }

        return res;
    }
};
