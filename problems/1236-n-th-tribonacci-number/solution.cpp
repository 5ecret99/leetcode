class Solution {
public:
    int tribonacci(int n) 
    {
        constexpr int MAX_N = 37;
        static array<int, MAX_N + 1> trib = [MAX_N]{
            array<int, MAX_N + 1> t;
            t[0] = 0;
            t[1] = 1;
            t[2] = 1;
            for(int i = 3; i < t.size(); ++i)
                t[i] = t[i - 1] + t[i - 2] + t[i - 3];
            
            return t;
        }();
        
        return trib[n];
    }
};
