class Solution {
public:
    long long minEnd(int n, long long x) 
    {
        long long i_x = 1;
        long long i_n = 1;

        while(i_n < n)
        {
            if((i_x & x) == 0)
            {
                if(i_n & (n - 1))
                    x|= i_x;

                i_n = i_n << 1;
            }

            i_x = i_x << 1;
        }

        
        return x;
    }
};
