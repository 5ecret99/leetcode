class Solution {
private:
    vector<vector<int>> res{};
    void helper(vector<int>& nums, vector<int>::iterator it){
        if(it == nums.end()){
            res.push_back(nums);
            return;
        }

        for(auto pt{it}; pt != nums.end(); ++pt){
            swap(*it, *pt);
            helper(nums, it + 1);
            swap(*it, *pt);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums, nums.begin());
        return res;
    }
};
