class Solution {
public:
    string maximumOddBinaryNumber(string& s) 
    {
        int n = s.size();
        int count = 0;
        for(int i = 0; i < n; ++i)
            if(s[i] == '1')
            {
                ++count;
                s[i] = '0';
            }
        
        s[n - 1] = '1';
        --count;
        
        for(int i = 0; i < count; ++i)
            s[i] = '1';
        
        return s;
    }
};
