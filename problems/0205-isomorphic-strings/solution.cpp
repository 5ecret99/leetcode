class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> s2i;
        unordered_map<char, int> t2i;
        for(int i = 0; i < s.size(); ++i)
        {
            auto dch = s2i.find(s[i]);
            auto tch = t2i.find(t[i]);
            if(dch == s2i.end() && tch == t2i.end())
            {
                s2i[s[i]] = t2i[t[i]] = i;
            }
            else if(dch != s2i.end() && tch != t2i.end() && dch->second == tch->second)
            {
                continue;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};
