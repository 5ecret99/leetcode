class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0){
            return false;
        }
        else if (x < 10){
            return true;
        }

        long reverse_x = 0;
        int temp_x = x;
        while(temp_x){
            reverse_x = 10 * reverse_x + temp_x % 10;
            temp_x/= 10;
        }

        return reverse_x == x;
    }
};