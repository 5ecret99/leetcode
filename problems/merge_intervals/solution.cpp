class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), 
        [](const vector<int>& a, const vector<int>& b ){return a[0] < b[0];});
        for(auto it = intervals.begin(); it < intervals.end() - 1; it++){
            if((*it)[1] >= (*(it + 1))[0]){
                auto next_it = it + 1;
                (*it)[0] = min((*it)[0], (*next_it)[0]);
                (*it)[1] = max((*it)[1], (*next_it)[1]);
                while(++next_it != intervals.end() && (*it)[1] >= (*next_it)[0]) 
                    (*it)[1] = max((*it)[1], (*next_it)[1]);
                
                intervals.erase(it + 1, next_it);
            }
        }
        
        return intervals;
    }
};