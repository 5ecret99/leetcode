class Solution 
{
private:
    static constexpr int N = 26;
public:
    int countCharacters(vector<string>& words, string& chars) 
    {
        array<int, N> chs{{0}};
        for(char ch : chars)
            chs[ch - 'a']++;
        
        int res = 0;
        for(auto& w : words)
        {
            array<int, N> ws{{0}};
            for(char ch : w)
                ws[ch - 'a']++;

            auto good_word = true;
            for(int i = 0; i < N; ++i)
                if(ws[i] > chs[i])
                {
                    good_word = false;
                    break;
                }

            if(good_word)
                res+= w.size();
        }
        
        return res; 
    }
};
