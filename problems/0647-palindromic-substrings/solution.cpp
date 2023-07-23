class Solution {
private:
    int _count{0};

    void helper(string& s, string::iterator begin, string::iterator end){
        while(begin != s.begin() - 1 && end != s.end() && *begin == *end){
            begin--;
            end++;
            _count++;
        }
    }
    
public:
    int countSubstrings(string s) {
        for(auto it = s.begin(); it != s.end(); it++){
            helper(s, it, it);
            helper(s, it, it + 1);
        }

        return _count;
    }
};
