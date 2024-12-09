class Solution 
{
private:
    array<double, 101> tower;
public:
    double champagneTower(int poured, int row, int glass) 
    {
        tower[0] = poured;
        for(int i = 1; i <= row; ++i)
            for(int j = i; j >= 0; --j)
                tower[j + 1]+= tower[j] = max(0.0, (tower[j] - 1) / 2.0);

        return min(1.0, tower[glass]);
    }
};
