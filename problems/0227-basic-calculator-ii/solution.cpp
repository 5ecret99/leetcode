class Solution {
    int compute(const string& s)
    {
        stack<int> numbers;
        int num{0};
        char sign = '+';

        for(int i = 0; i < s.size(); ++i)
        {
            if(isdigit(s[i]))
            {
                num = num * 10 - '0' + s[i];
            }
            
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || i + 1 == s.size())
            {
                switch(sign)
                {
                    case '+':
                        numbers.push(num);
                        break;
                    case '-':
                        numbers.push(-num);
                        break;
                    case '*':
                    {
                        auto temp = numbers.top() * num;
                        numbers.pop();
                        numbers.push(temp);
                        break;
                    }
                    case '/':
                    {
                        int temp = numbers.top() / num;
                        numbers.pop();
                        numbers.push(temp);
                        break; 
                    }
                }

                sign = s[i];
                num = 0;
            }
        }

        int total{0};
        while(!numbers.empty())
        {
            total+=numbers.top();
            numbers.pop();
        }

        return total;
    }
public:
    int calculate(string s) {
        return compute(s);
    }
};
