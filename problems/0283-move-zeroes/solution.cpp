class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        auto a = nums.begin();
        auto b = nums.begin();    
        while(b < nums.end())
        {
            if(*b != 0)
            {
                swap(*a, *b);
                a++;
            }

            b++;
        }
    }
};
