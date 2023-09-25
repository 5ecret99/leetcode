class Solution {
private:
    bool validPalindrome(const string& s, int low, int high, bool allow_skip = true){
        while(low < high){
            if(s[low] == s[high]){
                ++low;
                --high;
            }
            else if(allow_skip){
                return validPalindrome(s, low + 1, high, false) 
                    || validPalindrome(s, low, high - 1, false);
            }
            else{
                return false;
            } 
        }

        return true;
    }

public:
    bool validPalindrome(string s) {
        return validPalindrome(s, 0, s.size() - 1);
    }
};