class Solution 
{
private:
    int mod_exp(int a, int b, int c = 10)
    {
        a%=c;
        if(a == 0)
            return 0;

        int res = 1;
        while(b--)
            res = (res * a) % c;
        
        return res;
    }
public:
    vector<int> getGoodIndices(vector<vector<int>>& var, int target) 
    {
        vector<int> good_arr;
        for(int i = 0; i < var.size(); ++i)
            if (mod_exp(mod_exp(var[i][0], var[i][1]), var[i][2], var[i][3]) == target)
                good_arr.push_back(i);
        
        return good_arr;
    }
};
