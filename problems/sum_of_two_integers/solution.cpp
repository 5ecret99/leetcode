class Solution {
public:
    int getSum(unsigned int a, unsigned int b) {
        if(!b) return a;
        return getSum(a ^ b, (a & b) << 1);
    }
};