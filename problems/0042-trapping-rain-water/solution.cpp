class Solution {
public:
    int trap(vector<int>& height) {
        auto start = height.begin();
        auto end = height.end() - 1;
        int level{0};
        int water{0};

        while(start < end){
            int lower = *start < *end ? *start++ : *end--;
            level = max(level, lower);
            water+= level - lower;
        }

        return water;
    }
};
