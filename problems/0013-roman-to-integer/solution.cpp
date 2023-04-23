class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        unordered_map<char, int> mp = {
        {'M', 1000}, 
        {'D', 500},
        {'C', 100},
        {'L', 50},
        {'X', 10},
        {'V', 5},
        {'I', 1} };
        for(auto i = 0; i  < s.size(); i++ ){
            if(mp[s[i]] < mp[s[i + 1]]){
                res+= mp[s[i+1]] - mp[s[i]];
                i++;
            }
            else{
                res+=mp[s[i]];
            }
        }

        return res;
    }
};
