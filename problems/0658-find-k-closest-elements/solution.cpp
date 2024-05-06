class Solution 
{

public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        int min_pos = 0;
        int min_val = INT_MAX;
        for(int i = 0; i < arr.size(); ++i)
        {
            auto calc = abs(arr[i] - x);
            if(calc < min_val)
            {
                min_pos = i;
                min_val = calc;
            }
        } 

        int l = min_pos;
        int r = min_pos;
        while(r - l + 1 < k)
            if(l <= 0) ++r;
            else if(r + 1 >= arr.size()) --l;
            else if(abs(arr[l - 1] - x) - abs(arr[r + 1] - x) <= 0) --l;
            else ++r;

        return vector<int>(arr.begin() + l, arr.begin() + r + 1);
    }
};
