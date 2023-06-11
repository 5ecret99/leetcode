class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() < 2){return true;}
        auto low = s.begin();
        auto high = s.end() - 1;

        while(low < high){
            if(!isalnum(*low)){
                low++;
            }
            else if(!isalnum(*high)){
                high--;
            }
            else if(tolower(*low) == tolower(*high)){
                low++;
                high--;
            }
            else{
                return false;
            }
        }

        return true;
    }
};