class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        unsigned int mask{0};
        for(int i = 0; i < s.size(); ++i)
        {
            mask^= s[i];
            mask^= t[i];
        }
        
        return mask ^ *t.rbegin();
    }
};
