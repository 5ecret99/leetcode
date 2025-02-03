class Solution 
{
private:
    bool splitString(const string& s, int ind, long long goal) 
    {
        if(ind == s.size())
            return true;

        string curr = "";
        for(int i = ind; i < s.size(); ++i)
        {
            curr+= s[i];
            long long curr_num = stoull(curr);
            if(curr_num == goal )
            {
                if(splitString(s, i + 1, curr_num - 1))
                    return true;
            }
            else if(curr_num > goal)
                return false;
        }

        return false;
    }
public:
    bool splitString(const string& s) 
    {
        string curr = "";
        for(int i = 0; i < s.size() - 1; ++i)
        {
            curr+= s[i];
            long long curr_num = stoull(curr);
            if(splitString(s, i + 1, curr_num - 1))
                return true;
        }

        return false;
    }
};
