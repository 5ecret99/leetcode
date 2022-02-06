class Solution {
public:
    void rotate(vector<int>& nums,int start,int end)
        {
        int temp_start=start;
        int temp_end=end;
        while(temp_start<temp_end)
            {
            int temp=nums[temp_start];
            nums[temp_start]=nums[temp_end];
            nums[temp_end]=temp;
            temp_start++;
            temp_end--;
            }
        }
    void rotate(vector<int>& nums, int k) 
    {
    k=k%nums.size();
    rotate(nums,0,nums.size()-1);
    rotate(nums,0,k-1);
    rotate(nums,k,nums.size()-1);
    }
};
