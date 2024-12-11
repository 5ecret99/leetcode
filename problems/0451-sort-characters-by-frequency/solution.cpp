class Solution {
public:
    string frequencySort(string& s) 
    {
        unordered_map<char, int> mp;
        for(auto ch : s)
            mp[ch]++;
        
        vector<pair<char, int>> vec{mp.begin(), mp.end()};
        sort(vec.begin(), vec.end(), [](const auto& l, const auto& r){
            return l.second > r.second;
        });

        string res;
        for(const auto& [ch, cnt] : vec)
            res.append(cnt, ch);

        return res;

    }
};
