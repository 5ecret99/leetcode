class Solution {
public:
    int getSum(int a, int b) {
        while(b)
        {
            auto tmp{a};
            a^= b;
            b = (b & tmp) << 1;
        }
        
        return a;
    }
};
