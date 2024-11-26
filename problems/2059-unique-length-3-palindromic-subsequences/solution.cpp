class Solution 
{
private:
public:
    int countPalindromicSubsequence(string& s) 
    {

        unordered_map<char, int> first_pos;
        unordered_map<char, int> last_pos;

        for(int i = 0; i < s.size(); ++i)
        {
            if(!first_pos.contains(s[i]))
                first_pos[s[i]] = i;

            last_pos[s[i]] = i;
        }

        int res = 0;
        for(auto& [ch, first] : first_pos)
        {
            auto last = last_pos[ch];
            if(first < last)
            {
                unordered_set<char> uniq{s.begin() + first + 1,  s.begin() + last};
                res+= uniq.size();
            }
        }

        return res; 
    }
};
