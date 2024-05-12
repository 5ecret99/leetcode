class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int ind = 0;
        for(auto n : nums)
            if(ind < 2 || n != nums[ind - 2])
                nums[ind++] = n;

        return ind;
    }
};
