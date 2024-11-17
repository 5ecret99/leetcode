class Solution 
{
private:
    bitset<10001> seen;
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        int n = nums.size();
        int duplicated = 0;
        int missing = 0;
        seen.reset();
        for(int i = 0; i < nums.size(); ++i)
        {
            missing^= i + 1;
            if(seen.test(nums[i]))
                duplicated = nums[i];
            else
            {
                seen.set(nums[i]);
                missing^= nums[i];
            }
        }

        return {duplicated, missing};
    }
};
