class Solution {
private:
    int compute(const string& s)
    {
        stack<int> op({1});
        int result{0};
        int num{0};
        int sign{1};
        char token;
        for(auto ch : s)
        {
            if(isdigit(ch))
            {
                num = num * 10 + - '0' + ch;
                continue;
            }

            result+= op.top() * sign * num;
            num = 0;
            switch(ch)
            {
                case '+':
                    sign = 1;
                    break;
                case '-':
                    sign = -1;
                    break;
                case ')':
                    op.pop();
                    break;
                case '(':
                    op.push(op.top() * sign);
                    sign = 1;
                    break;
            }
        }

        return result + op.top() * sign * num;
    }
public:
    int calculate(string s) {
        return compute(s);
    }
};
