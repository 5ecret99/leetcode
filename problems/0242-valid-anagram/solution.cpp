class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> ss(26,0);
        auto i = s.size();
        
        while(i--){
            ss[s[i] - 'a']++;
            ss[t[i] - 'a']--;
        }

        for(auto ff:ss)
           if(ff) return false;

        return true;
    }
};
