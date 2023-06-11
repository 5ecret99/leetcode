class Solution {
public:
    string minWindow(string s, string t) {
    unordered_map<char, int> map;
    for(auto ch:t)
        map[ch]++;
    
    int char_left = map.size();
    int min_window = INT_MAX;
    auto start = s.begin();
    auto jt = s.begin();
    for(auto it = s.begin(); it != s.end(); it++){
        if(--map[*it] == 0)
            char_left--;
        
        while(char_left == 0){   
            auto curr_window = (int) distance(jt, it);
            if( min_window > curr_window + 1){
                min_window = curr_window + 1;
                start = jt;
            }

            if(++map[*(it - curr_window)] > 0)
                char_left++;
            
            jt++;
        }
    }

    return min_window == INT_MAX ? "" : string(start, start + min_window);
    }
};