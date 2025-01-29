class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
        vector<int> res;
        sort(potions.begin(), potions.end());
        for(long long spell : spells)
        {
            auto it = lower_bound(potions.begin(), potions.end(), (success + spell - 1) / spell);
            res.push_back(distance(it, potions.end()));
        }
        
        return res;
    }
};
