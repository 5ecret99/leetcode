class Solution {
public:
    bool checkPossibility(vector<int>& nums) 
    {
        bool allowed_mod = true;
        if(nums.size() > 1 && nums[0] > nums[1])
        {
            nums[0] = nums[1];
            allowed_mod = false;
        }

        for(int i = 1; i < nums.size() - 1; ++i)
        {
            if(nums[i] > nums[i + 1])
            {
                if(!allowed_mod)
                    return false;

                if(nums[i + 1] >= nums[i - 1])
                    nums[i] = nums[i - 1];
                else
                    nums[i + 1] = nums[i];
                
                allowed_mod = false;
            }
        }

        return true;
    }
};
