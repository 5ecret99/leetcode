class Solution 
{
private:

public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) 
    {
        map<double, int> ratios;
        long long res = 0;
        for(auto& r : rectangles)
            res+= ratios[static_cast<double>(r[0]) / r[1]]++;

        return res;
    }
};
