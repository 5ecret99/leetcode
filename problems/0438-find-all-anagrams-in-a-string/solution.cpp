class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        vector<int> pcount(26, 0);
        for(auto ch : p)
            pcount[ch - 'a']++;

        vector<int> scount(26, 0);
        vector<int> res;
        for(int r = 0; r < s.size(); ++r)
        {
            scount[s[r] - 'a']++;
            if(r >= p.size())
                scount[s[r - p.size()] - 'a']--;
            
            if(scount == pcount)
                res.push_back(1 + r - p.size());
        }

        return res;
    }
};
