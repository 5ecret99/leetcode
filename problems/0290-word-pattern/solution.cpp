class Solution {
public:
    bool wordPattern(string pattern, string s)
    {
        int i = 0;
        unordered_map<char, int> p2i;
        unordered_map<string, int> w2i;
        istringstream in(s);
        string word;

        while(in >> word)
        {
            if (i == pattern.size() || p2i[pattern[i]] != w2i[word])
                return false;
            
            p2i[pattern[i++]] = w2i[word] = i + 1;
        }
        
        return i == pattern.size();
    }
};
