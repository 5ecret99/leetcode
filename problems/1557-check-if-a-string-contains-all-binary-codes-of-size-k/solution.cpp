class Solution {
public:
    bool hasAllCodes(string s, int k) 
    {
        int res = 1 << k;
        unordered_set<string> sub;
        for(int i = 0; i + k <= s.size(); ++i)
        {
            sub.insert(s.substr(i, k));
            if(sub.size() == res)
                return true;
        }

        return false;
    }
};
