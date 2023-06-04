class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        while(low < nums.size() && nums[low] < target){
            low++;
        }
        return low;
    }
};
