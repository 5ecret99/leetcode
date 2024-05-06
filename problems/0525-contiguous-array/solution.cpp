class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        unordered_map<int, int> count_pos;
        count_pos[0] = -1;
        int counter = 0;
        int max_len = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            counter+= nums[i] ? 1 : -1;
            auto it = count_pos.find(counter);
            if(it != count_pos.end())
                max_len = max(max_len, i - it->second);
            else
                count_pos[counter] = i;
        }

        return max_len;
    }
};
