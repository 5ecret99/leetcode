class Solution {
public:
    int maxScore(string& s) 
    {
        int curr = s[0] == '0';
        for(int i = 1; i < s.size(); ++i)
            curr+= s[i] == '1';
        
        int res = curr;
        for(int i = 1; i + 1 < s.size(); ++i)
        {
            curr+= 2 * (s[i] == '0') - 1;
            res = max(res, curr);
        }

        return res;
    }
};
