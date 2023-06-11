class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> set(256, false);
        int curr_len = 0;
        int max_len = 0;
        for(auto it = s.begin(); it != s.end(); it++){
            if(set[*it]){
                for(auto jt = it - curr_len; *jt != *it; jt++){
                    curr_len--; 
                    set[*jt] = false;
                }
            }
            else{
                set[*it] = true;
                curr_len++;
                max_len = max(max_len, curr_len);
            }
        }

        return max_len;    
    }
};