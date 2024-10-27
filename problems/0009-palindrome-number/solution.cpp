class Solution {
public:
    bool isPalindrome(int x) 
    {
        int rx = 0;
        int tmp = x; 
        while(tmp > 0)
        {
            if(rx > INT_MAX / 10)
                return false;
            rx = rx * 10 + tmp % 10;
            tmp/= 10;
        }
        
        return x == rx;
    }
};
