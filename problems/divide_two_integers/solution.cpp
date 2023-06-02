class Solution {
public:
    int divide(int dividend, int divisor) {
        auto positive = dividend < 0 == divisor < 0;
        long int udividend = abs(dividend);
        long int udivisor = abs(divisor);
        if(udivisor == 1){
            if(dividend == INT_MIN){
                return positive ? INT_MAX : INT_MIN;
            }
            return positive ? udividend : -udividend;
        }
        
        int res=0;
        while(udivisor <= udividend) {
            long int mul = udivisor;
            long int tmp = 1;
            while(mul <= udividend - mul) {
                mul+=mul;
                tmp+=tmp;
            }
            res+=tmp;
            udividend-=mul;
        }
         
        return positive ? res : -res;
    }
};