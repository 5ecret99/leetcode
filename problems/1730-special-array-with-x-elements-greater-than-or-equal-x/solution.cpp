class Solution {
public:
    int specialArray(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int k = nums.size();
        for(int i = 0; i < nums.size(); ++i)
            if(k <= nums[i])
                return k;
            else if(--k <= nums[i])
                return -1;

        return -1;
    }
};
