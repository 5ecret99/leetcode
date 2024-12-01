class Solution 
{
private:
    static constexpr int SEQ_SIZE = 10;
public:
    vector<string> findRepeatedDnaSequences(string_view s)
    {
        int n = s.size();
        unordered_map<string_view, int> DNA;
        for(int i = 0; i <= n - SEQ_SIZE; ++i)
            DNA[s.substr(i, SEQ_SIZE)]++;
        
        vector<string> res;
        for(const auto& [seq, cnt] : DNA)
            if(cnt > 1)
                res.push_back(string(seq));

       return res;
    }
};
