class Solution {
public:
    string pushDominoes(string& d) 
    {
        int prev = 0;
        for(int i = 0; i < d.size(); ++i)
        {
            if(d[i] == 'L')
            {
                if(d[prev] == 'R')
                {
                    int l = prev;
                    int r = i;
                    while(++l < --r)
                    {
                        d[l] = 'R';
                        d[r] = 'L';
                    }
                }
                else
                    for(int j = i; j >= prev; --j)
                        d[j] = 'L';
                        
                prev = i;
            }
            else if(d[i] == 'R')
            {
                if(d[prev] == 'R')
                    for(int j = prev; j < i; ++j)
                        d[j] = 'R';

                prev = i;
            }
        } 


        if(d[prev] == 'R')
            for(int j = prev; j < d.size(); ++j)
                d[j] = 'R';

        return d;
    }
};
