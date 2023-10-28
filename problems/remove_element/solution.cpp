class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size() - 1;
        int i = 0;
        while(i <= n){
            if(nums[i] == val)
                nums[i] = nums[n--];
            else
                ++i;
        }

        return n + 1;
    }
};