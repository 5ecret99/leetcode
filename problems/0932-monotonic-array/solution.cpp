class Solution {
public:
    bool isMonotonic(vector<int>& nums) 
    {
        auto cmp = nums[0] < nums[nums.size() - 1] 
            ? [](int a, int b){return a <= b;}
            : [](int a, int b){return a >= b;};

        for(int i = 1; i < nums.size(); ++i)
            if(!cmp(nums[i - 1], nums[i])) 
                return false;
        
        return true;
    }
};
