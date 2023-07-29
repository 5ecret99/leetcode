class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_jump = 0;
        for(int i = 0; i <= max_jump; i++){
            max_jump = max(i + nums[i], max_jump);
            if(max_jump >= nums.size() - 1){return true;}
        }

        return false;
    }
};
