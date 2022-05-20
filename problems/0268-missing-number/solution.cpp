class Solution {
public:
    int missingNumber(vector<int>& nums) {
    int length=nums.size();
    int asum=0;
    for(int i=0;i<length;i++) asum+=nums[i];
    
    return (length+1)*length/2-asum;     
    }
};
