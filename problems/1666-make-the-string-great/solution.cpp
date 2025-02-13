class Solution {
public:
    string makeGood(const string& s) 
    {
        stack<char> st;
        for(char ch : s)
            if(!st.empty() && abs(st.top() - ch) == 'a' - 'A')
                st.pop();
            else
                st.push(ch);

        string res;
        while(!st.empty())
        {
            res+= st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
