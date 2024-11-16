class Solution {
public:
    int minOperations(string& s) 
    {
        int odd1 = 0;
        int even1 = 0;
        for(int i = 0; i < s.size(); ++i)
            i & 1 
            ? s[i] == '0' ? ++odd1 : ++even1
            : s[i] == '0' ? ++even1 : ++odd1;
        
        return min(odd1, even1);
    }
};
