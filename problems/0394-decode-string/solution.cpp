class Solution 
{
private:
public:
    string decodeString(string s) 
    {
        stack<int> times;
        stack<string> strings;
        string res;
        int num = 0;
        for(char ch : s)
        {
            if(isdigit(ch))
            {
                num = 10 * num + (ch - '0');
            }
            else if(isalpha(ch))
            {
                res.push_back(ch);
            }
            else if(ch == '[')
            {
                strings.push(res);
                times.push(num);
                res.clear();
                num = 0;
            }
            else if(ch == ']')
            {
                auto x_times = [](int x, string_view str) {
                    string res;
                    while(x--) res += str;
                    return res;
                };

                res = strings.top() + x_times(times.top(), res);
                strings.pop();
                times.pop();
            }
        }

        return res;
    }
};
