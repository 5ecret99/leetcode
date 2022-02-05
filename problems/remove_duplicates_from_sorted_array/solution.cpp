class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index=0;
        for(int i=0;i<nums.size();i++)
            {
            int flag=0;
            for(int r=i-1;r>=0;r--)
                {
                if(nums[i]==nums[r])
                    {
                    flag=1;
                    break;
                    }
                }
            if(flag==0)
                {
                nums[index]=nums[i];
                index++;
                }
            }
        return index;
    }
};