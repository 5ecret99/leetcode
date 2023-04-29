class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++){
            int low = i + 1, high = nums.size() - 1;
            while(low < high){
                auto sum = nums[i] + nums[low] + nums[high];
                if (sum > target){
                    high--;
                }
                else if(sum < target){
                    low++;
                }
                else{
                    return sum;
                }

                if (abs(target - sum) < abs(target - closest)){
                    closest = sum;
                }
            }
        }

        return closest;
    }
};
