class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto cmp = [](int l, int r){
            auto sl = to_string(l);
            auto sr = to_string(r);
            return sl + sr > sr + sl;
        };

        sort(nums.begin(), nums.end(), cmp);
        stringstream ss;
        for(const auto& num : nums)
            ss << num;

        auto res{ss.str()};
        return res[0] == '0' ? "0" : res;
    }
};