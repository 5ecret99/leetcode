class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) 
    {
        if(n == 0) return true;
        for(int i = 0; i < f.size(); ++i) 
        {
            if((i == 0 || f[i - 1] == 0) 
                && f[i] == 0 
                && ( i + 1 >= f.size() || f[i + 1] == 0))
            {
                --n;
                f[i] = 1;
                if(n == 0) return true;
            }
        }

        return false;
    }
};
