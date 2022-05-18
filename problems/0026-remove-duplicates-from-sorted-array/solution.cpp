class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //unordered_set<int> st;
        int index=1;
        
        for(int i=1;i<nums.size();i++)
            {
            if(nums[i]==nums[i-1]) continue;
            
            nums[index]=nums[i];
            index++; 
            }
        return index;
    }
};
