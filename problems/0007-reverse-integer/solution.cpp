class Solution {
public:
    int reverse(int x) {
        long res = 0;
        while(x != 0){
            res = res * 10 + x % 10;
            x /= 10;
        }

        return res >= INT_MIN && res <= INT_MAX ? static_cast<int>(res) : 0;
    }
};
