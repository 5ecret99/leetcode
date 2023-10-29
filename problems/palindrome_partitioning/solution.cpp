class Solution {
private:
vector<vector<string>> particions{};
vector<string> curr_part{};

bool is_palindrome(string::iterator left, string::iterator right)
{
    while(left <= right)
        if(*left++ != *right--) 
            return false;
    
    return true;
}

void particion(const string& s, string::iterator start)
{
    if(start == s.end())
    {
        particions.push_back(curr_part);
        return;
    }

    for(auto it = start; it < s.end(); ++it)
        if(is_palindrome(start, it))
        {
            curr_part.push_back(string(start, it + 1));
            particion(s, it + 1);
            curr_part.pop_back();
        }
}

public:
    vector<vector<string>> partition(string s) 
    {
        particion(s, s.begin());
        return particions;
    }
};