class Solution 
{
private:
    static constexpr int MAX_N = 5 * 1000000;
    bitset<MAX_N> prime{ bitset<MAX_N>().set()};
public:
    int countPrimes(int n) 
    {
        if(n < 3)
            return 0;

        int counter = n/2;
        for(int i = 3; i * i < n; i+= 2)
            if(prime.test(i))
            {
                for(int j = i * i; j < n; j+= i * 2)
                    if(prime.test(j))
                    {
                        --counter;
                        prime.set(j, false);
                    }
            }
        
        return counter;
    }
};
