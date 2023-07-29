class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto it = intervals.begin();
        for(; it < intervals.end(); it++){
            if(newInterval[1] < (*it)[0]){
               intervals.insert(it, 1, newInterval);
               break;
            }
            else if(newInterval[0] > (*it)[1]) continue;
            else{
                (*it)[0] = min(newInterval[0], (*it)[0]);
                (*it)[1] = max(newInterval[1], (*it)[1]);
                auto prev_it = it;
                while(++it != intervals.end() && (*prev_it)[1] >= (*it)[0]) 
                    (*prev_it)[1] = max((*it)[1], (*prev_it)[1]);
                
                intervals.erase(prev_it + 1, it);
                it = intervals.begin();
                break;
            }
        }
        
        if (it == intervals.end()) intervals.push_back(newInterval);

        return intervals;
    }
};
