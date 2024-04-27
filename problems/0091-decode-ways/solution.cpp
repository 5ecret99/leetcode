class Solution {
private:
public:
    int numDecodings(string s) 
    {
        if(s.empty() || s[0] == '0') return 0;
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= s.size(); ++i)
        {
            int one_digit = s[i - 1] - '0';
            if(one_digit != 0)
                dp[i]+= dp[i - 1];
            
            int two_digit = (s[i - 2] - '0') * 10 + one_digit;
            if(10 <= two_digit && two_digit <= 26)
                dp[i]+= dp[i - 2];
        }

        return dp[s.size()];       
    }
};
