class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 0 || nums.size() < k) return {};
        vector<int> res;
        multiset<int> set;
        for(auto i = 0; i < nums.size(); ++i){
            if(i >= k)  set.erase(set.find(nums[i - k]));
            set.insert(nums[i]);
            if(i >= k - 1)  res.push_back(*set.rbegin());
        }
    
        return res;
    }
};