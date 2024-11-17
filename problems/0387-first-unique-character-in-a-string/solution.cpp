class Solution 
{
private:
    array<int, 26> counter;
public:
    int firstUniqChar(string& s) 
    {
        for(auto ch : s)
            counter[ch - 'a']++;

        for(int i = 0; i < s.size(); ++i)
            if (counter[s[i] - 'a'] == 1)
                return i;
        
        return -1;
    }
};
