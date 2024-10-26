class Solution {
private:
    std::bitset<100000> checker;
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        int n = nums.size();
        for(auto num : nums)
            checker.set(num);

        vector<int> res;
        for(int i = 1; i <= n; ++i)
            if(!checker.test(i))
                res.push_back(i);

        return res;
    }
};
