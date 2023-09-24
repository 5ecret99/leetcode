class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs{{}};
        for(const auto num : nums){
            size_t n = subs.size();
            for(size_t i = 0; i < n; ++i){
                subs.push_back(subs[i]);
                subs.back().push_back(num);
            }
        }
       
       return subs;
    }
};