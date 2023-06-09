class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            auto it = map.find(nums[i]);
            if(it != map.end()){
                res.push_back(it->second);
                res.push_back(i);
                map.erase(it);
            }
            else{
                map.insert({target - nums[i], i});
            }
        }

        return res;
    }
};
