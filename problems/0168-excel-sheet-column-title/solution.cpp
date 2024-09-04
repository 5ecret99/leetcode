class Solution {
public:
    string convertToTitle(int num) 
    {
        string res;
        while(num--)
        {
            res.push_back('A' + num % 26);
            num/= 26;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
