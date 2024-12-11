class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res(n / 3);
        for(int i = 2; i < nums.size(); i+= 3)
        {
            if(nums[i] - nums[i - 2] > k)
                return {};
            
            res[i / 3].assign({nums[i - 2], nums[i - 1], nums[i]});
        }

        return res;
    }
};
