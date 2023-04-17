class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> cache(s.length() + 1, vector<int>(p.length(), -1));
        std::function<bool(int, int)> dfs = [&](int is, int ip){
            if(ip >= p.length())
                return is == s.length();
            
            if(cache[is][ip] >= 0)
                return cache[is][ip] == 1;
            
            auto match =  is < s.length() && (s[is] == p[ip] || p[ip] == '.');
            cache[is][ip] = (ip + 1 < p.length() && p[ip + 1] == '*')
            ? dfs(is, ip + 2) || (match && dfs(is + 1, ip))
            : match && dfs(is + 1, ip + 1);

            return cache[is][ip] == 1;
        };

        return dfs(0, 0);
    }
};
