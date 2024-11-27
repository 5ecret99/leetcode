class Solution {
public:
    int minSwaps(const string& s) 
    {
        int cnt = 0;
        for(auto ch : s)
            if(ch == '[')
                ++cnt;
            else if(cnt)
                --cnt;

        return  (cnt + 1)/ 2; 
    }
};
