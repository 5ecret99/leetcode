class Solution 
{
private:
    array<int, 26> first_pos;
public:
    int maxLengthBetweenEqualCharacters(string& s) 
    {
        first_pos.fill(-1);
        int max_len = -1;
        for(int i = 0; i < s.size(); ++i)
            if(first_pos[s[i] - 'a'] == -1)
                first_pos[s[i] - 'a'] = i + 1;
            else
                max_len = max(max_len, i - first_pos[s[i] - 'a']);

        return max_len;
    }
};
