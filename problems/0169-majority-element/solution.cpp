class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        int count = 0;
        int cantidate = 0;
        for(auto n : nums)
        {
            if(!count) cantidate = n;
            if(cantidate == n) ++count;
            else --count;
        }

        return cantidate;
    }
};
