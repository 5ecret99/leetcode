class Solution {
private:
    vector<vector<int>> res{};
    vector<int> combo{};
    void helper(vector<int>& candidates, int target, int sum = 0, int index = 0){
        if(sum > target) return;

        if(sum == target){
            res.push_back(combo);
            return;
        }

        for(int i = index; i < candidates.size(); i++){
            combo.push_back(candidates[i]);
            sum+=candidates[i];
            helper(candidates, target, sum, i);
            combo.pop_back();
            sum-=candidates[i];
        }
    }
public:
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        helper(candidates, target);
        return res;
    }
};