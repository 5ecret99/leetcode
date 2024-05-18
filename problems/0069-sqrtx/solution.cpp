class Solution {
public:
    int mySqrt(int x) 
    {
        int right = x;
        int left = 1;
        while(left <= right)
        {
            long mid = left + (right - left) / 2;
            long sqr = mid * mid;
            if(sqr < x)
                left = mid + 1;
            else if(sqr > x)
                right = mid - 1;
            else
                return mid;
        }

        return right;
    }
};
