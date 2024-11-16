class Solution {
public:
    bool makeEqual(vector<string>& words) 
    {
        array<int, 26> checker;
        for(auto& w : words)
            for(auto ch : w)
                checker[ch - 'a']++;

        for(auto b : checker)
            if(b % words.size())
                return false;

        return true;
    }
};
