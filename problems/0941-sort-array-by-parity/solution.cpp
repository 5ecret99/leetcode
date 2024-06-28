class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) 
    {
        auto left = nums.begin();
        auto right = nums.end() - 1;

        while(left != right)
            if(*left & 1)
                swap(*left, *right--);
            else
                left++;
        
        return nums;
    }
};
