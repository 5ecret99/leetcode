class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        auto g_it = g.begin();
        auto s_it = s.begin();
        int child_count = 0;

        while(s_it != s.end() && g_it != g.end())
            if(*s_it >= *g_it)
            {
                s_it++;
                g_it++;
                child_count++;
            }
            else
                s_it++;
        
        return child_count;
    }
};
