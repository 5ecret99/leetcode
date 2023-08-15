class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> index_height;
        int max_area{0};
        auto stack_pop = [&index_height, &max_area](int i, int height = -1){
            int start = i;
            while(!index_height.empty() && index_height.top().second >= height){
                max_area = max(max_area, (i - index_height.top().first) * index_height.top().second);
                start = index_height.top().first;
                index_height.pop();
            }

            return start;
        };

        for(int i = 0; i < heights.size(); ++i)
            index_height.push({stack_pop(i, heights[i]), heights[i]});
        
        stack_pop(heights.size());
        return max_area;
    }
};