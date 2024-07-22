class Solution {
private:
    string_view generate(string& str)
    {
        int ind = 0;
        for(int i = 0; i < str.size(); ++i)
            if(str[i] != '#')
                str[ind++] = str[i];
            else if(ind)
                --ind;

        return string_view(str.c_str(), ind);
    }
public:
    bool backspaceCompare(string s, string t) 
    {
        return generate(s) == generate(t);
    }
};
