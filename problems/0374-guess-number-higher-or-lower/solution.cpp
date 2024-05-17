/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int right) 
    {
        int left = 1;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            switch(guess(mid))
            {
                case 1:
                    left = mid + 1;
                    break; 
                case -1:
                    right = mid - 1;
                    break;
                case 0:
                    return mid;
            }
        }

        return -1;
    }
};
