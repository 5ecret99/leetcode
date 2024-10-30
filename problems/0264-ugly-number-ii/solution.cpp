class Solution 
{
public:
    int nthUglyNumber(int n) 
    {
        static vector<int> ugly{[]{
        vector<int> ugly;
        long long m = INT_MAX;
        for(long long a = 1; a <= m; a*=2)
            for(long long b = a; b <= m; b*=3)
                for(long long c = b; c <= m; c*=5)
                    ugly.push_back(c);

        sort(ugly.begin(), ugly.end());
        return ugly;
        }()};

        return ugly[n - 1];    
    }
};
