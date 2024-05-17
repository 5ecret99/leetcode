class Solution {
public:
    int arrangeCoins(int n) 
    {
        int right= n;
        int left = 1;
        while(left <= right)
        {
            long mid = left + (right - left) / 2;
            long calc = mid * (mid + 1) / 2;
            if(calc < n)
                left = mid + 1;
            else if(calc > n)
                right = mid - 1;
            else
                return mid;
        }

        return right;
    }
};
