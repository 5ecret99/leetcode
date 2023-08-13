class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return false;
        unordered_map<char, int> mp;
        unordered_map<char, int> window;

        for(int i = 0; i < s1.size(); ++i){
            ++mp[s1[i]];
            ++window[s2[i]];
        }

        if(window == mp) return true;
        auto begin = s2.begin();
        for(auto it = s2.begin() + s1.size(); it != s2.end(); ++it){
            if(window[*begin] == 1)
                window.erase(*begin);
            else
                --window[*begin];
            
            ++begin;
            ++window[*it];
            if(mp == window) return true;
        }

        return false;
    }
};