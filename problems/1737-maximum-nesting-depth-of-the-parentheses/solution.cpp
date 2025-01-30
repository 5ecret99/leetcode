class Solution {
public:
    int maxDepth(const string& s) 
    {
        int p_count = 0;
        int max_depth = 0;
        for(auto ch : s)
            if(ch == '(')
            {
                ++p_count;
                max_depth = max(max_depth, p_count);
            }
            else if(ch == ')')
                --p_count;

        return max_depth;
    }
};
