class Solution {
public:
    bool isSubsequence(const string& s, const string& t, int i = 0, int j = 0) { 
        if(i == s.size()) return true;
        if(j == t.size()) return false;
        if(s.size() - i > t.size() - j) return false;

        if(s[i] == t[j]) return isSubsequence(s, t, ++i, ++j);

        return isSubsequence(s, t, i, ++j);
    }
};
