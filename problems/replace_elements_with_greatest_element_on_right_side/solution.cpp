class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int prev_max = -1;
        for(auto it = arr.rbegin(); it != arr.rend(); ++it){
            auto temp = *it;
            *it = prev_max;
            prev_max = max(prev_max, temp);
        }

        return arr;
    }
};