class Solution {
public:
    long long largestPerimeter(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        long long perimeter = accumulate(nums.begin(), nums.end(), 0LL);
        for(int i = nums.size() - 1; i >= 2; --i)
            if(perimeter > 2 * nums[i])
                return perimeter;
            else
                perimeter-= nums[i];
        
        return -1;
    }
};
