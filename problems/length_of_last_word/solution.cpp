class Solution {
public:
    int lengthOfLastWord(const string& s) {
        auto it = s.rbegin();
        while(it != s.rend() && *it == ' ')
            ++it;
        
        int counter{0};
        while(it != s.rend() && *it != ' '){
            ++it;
            ++counter;
        }

    return counter;
    }
};