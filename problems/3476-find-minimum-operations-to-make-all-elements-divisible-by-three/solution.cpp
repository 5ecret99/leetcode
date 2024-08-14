class Solution {
public:
    int minimumOperations(vector<int>& nums) 
    {
        int op_count = 0;
        for(auto num : nums)
            if(num % 3)
                ++op_count;

        return op_count;
    }
};
