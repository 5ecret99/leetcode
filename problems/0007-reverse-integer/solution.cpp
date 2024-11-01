class Solution {
public:
    int reverse(int x) 
    {
        long res{0};
        while(x != 0)
        {
            res = res * 10 + x % 10;
            x/= 10;
        }
        
        return res > INT_MAX ? 0 
                : res < INT_MIN ? 0
                : res;
    }
};
