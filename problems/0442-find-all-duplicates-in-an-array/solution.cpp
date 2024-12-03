class Solution 
{
private:
    bitset<100000> checker;
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        vector<int> res;
        for(auto n : nums)
        {
            if(checker.test(n))
                res.push_back(n);
            else
                checker.set(n);
        }

        return res;    
    }
};
