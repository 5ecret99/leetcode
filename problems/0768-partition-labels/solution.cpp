class Solution {
public:
    vector<int> partitionLabels(const string& s) {
        int last_pos[26]{0};
        for(int i = 0; i < s.size(); ++i) 
            last_pos[s[i] - 'a'] = i; 
        
        int start{-1};
        int end{0};
        vector<int> res;
        for(int i = 0; i < s.size(); ++i)
            if((end = max(end, last_pos[s[i] - 'a'])) == i){
                res.push_back(i - start);
                start = i;
            }
        
        return res;
    }
};
