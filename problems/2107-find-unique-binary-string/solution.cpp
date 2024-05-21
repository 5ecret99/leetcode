class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) 
    {
        string res(nums[0].size(), '0');
        for(int i = 0; i < nums.size(); ++i)
            if(nums[i][i] == '0')
                res[i] = '1';
        
        return res;
    }
};
