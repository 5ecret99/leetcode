class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {return a[1] < b[1];});
        int erased{0};
        auto prev{intervals.begin()};
        for(auto it{prev + 1}; it != intervals.end(); ++it)
            if(prev->at(1) > it->at(0))
                ++erased;
            else
                prev = it;

        return erased;
    }
};
