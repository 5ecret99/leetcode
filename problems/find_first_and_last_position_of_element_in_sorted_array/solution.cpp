class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        auto found = false;
        while(low <= high){
            found = nums[low] ==  target && nums[high] == target;
            if(found) break;

            if(nums[low] < target){
                low++;
            }
            else if(target < nums[high]){
                high--;
            }
        }

        return found ? vector<int>({low, high}) : vector<int>({-1, -1});
    }
};