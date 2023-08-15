class Solution {
public:
    int helper(vector<int>& nums, int target,int start, int end){
        if(start > end) return -1;
        int mid = start + (end - start) / 2;
        if(nums[mid] == target) return mid;
        
        return target < nums[mid] ? helper(nums, target, start, mid - 1) 
        : helper(nums, target, mid + 1, end);
    }
    int search(vector<int>& nums, int target) {
        return helper(nums, target, 0, nums.size() - 1);
    }
};