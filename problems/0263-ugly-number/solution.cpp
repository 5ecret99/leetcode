class Solution {
public:
    bool isUgly(int n) 
    {
        for(; n && (n & 1) == 0; n>>= 1);
        for(; n && n % 3 == 0; n/= 3);
        for(; n && n % 5 == 0; n/= 5);

        return n == 1;
    }
};
