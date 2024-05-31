class NumArray 
{
private:
    vector<int> prefix_sum_;
public:
    NumArray(vector<int>& nums) 
    {
        int n = nums.size();
        prefix_sum_.resize(n + 1);
        prefix_sum_[0] = 0;
        for(int i = 0; i < n; ++i)
            prefix_sum_[i + 1] = prefix_sum_[i] + nums[i];
    }
    
    int sumRange(int left, int right) 
    {
        return prefix_sum_[right + 1] - prefix_sum_[left];    
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
