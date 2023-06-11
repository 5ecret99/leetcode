class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> map;
        int curr_len = 0;
        int max_len = 0;
        int max_count = 0;
        for(auto it = s.begin(); it != s.end(); it++){
            map[*it]++;
            curr_len++;
            max_count = max(max_count, map[*it]);
            if(curr_len - max_count > k){
                map[*(it - curr_len + 1)]--;
                curr_len--;
            }

            max_len = max(max_len, curr_len);
        }

        return max_len;
    }
};