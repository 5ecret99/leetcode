class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res{};
        for(int i =0; i < nums.size() - 2; i++){
            int low = i + 1, high = nums.size() - 1;
            while(low < high){
                auto sum = nums[i] + nums[low] + nums[high];
                if( sum < 0){
                    low++;
                }
                else if (sum > 0){
                    high--;
                }
                else{
                    res.push_back({nums[i], nums[low], nums[high]});
                    auto temp_low = low, temp_high = high;
                    while(low < high && nums[low] == nums[temp_low]) low++;
                    while(low < high && nums[high] == nums[temp_high]) high--;
                }
            }

            while(i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
        }

        return res;
    }
};
