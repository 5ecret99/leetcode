class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(auto& num: nums)
            set.insert(num);
        
        int max_streak = 0;
        for(auto num: set){
            auto temp = set.find(num - 1);
            if(temp == set.end()){
                int curr_streak = 1;
                num++;
                temp = set.find(num);
                while(temp != set.end()){
                    curr_streak++;
                    num++;
                    temp = set.find(num);
                }

                max_streak = max(curr_streak, max_streak);
            }
        }

        return max_streak;
    }
};
