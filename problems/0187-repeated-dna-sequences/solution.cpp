class Solution 
{
private:
    static constexpr int SEQ_SIZE = 10;
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        int n = s.size();
        unordered_map<string, int> DNA;
        for(int i = 0; i <= n - SEQ_SIZE; ++i)
            DNA[s.substr(i, SEQ_SIZE)]++;
        
        vector<string> res;
        for(auto& it : DNA)
            if(it.second > 1)
                res.push_back(it.first);

       return res;
    }
};
