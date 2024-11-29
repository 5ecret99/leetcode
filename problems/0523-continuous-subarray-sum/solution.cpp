class Solution 
{
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int, int> sums;
        sums[0] = -1;
        int sum = 0;;

        for(int i = 0; i < nums.size(); ++i)
        {
            sum+= nums[i];
            auto it = sums.find(sum % k);
            if(it == sums.end())
                sums[sum % k] = i;
            else if(i - it->second >= 2)
                return true;
        }

        return false;
    }
};
