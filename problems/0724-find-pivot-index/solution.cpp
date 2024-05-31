class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int curr = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(total - curr - nums[i] == curr)
                return i;
            
            curr+= nums[i];
        }

        return -1; 
    }
};
