class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int min_p = 1;
        int max_p = 1;
        int res = INT_MIN;
        for(auto num : nums){
            if( num < 0) swap(min_p, max_p);
            max_p = max(max_p * num, num);
            min_p = min(min_p * num, num);

            res = max(res, max_p);
        }

        return res;
    }
};