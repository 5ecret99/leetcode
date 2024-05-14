class Solution {
public:
    int deleteAndEarn(vector<int>& nums) 
    {
        unordered_map<int, int> counter;
        int n = 0;
        for(auto num : nums)
        {
            counter[num]++;
            n = max(n, num);
        }

        int prev = 0;
        int curr = 0;
        for(int i = 1; i <= n; ++i)
        {
            int temp = curr;
            curr = max(prev + i * counter[i], curr);
            prev = temp;
        }
        
        return curr;
    }
};
