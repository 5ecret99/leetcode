class Solution {
public:
    int longestPalindrome(string s) 
    {
        unordered_map<char, int> mp;
        for(auto ch : s)
            mp[ch]++;

        int len{0};
        int contains_odd{0};
        for(auto& [_, count] : mp)
        {
            len+= count >> 1 << 1;
            if(count & 1) contains_odd = 1;
        }
        
        return len + contains_odd;
    }
};
