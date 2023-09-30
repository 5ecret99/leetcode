class Solution {
private:
    void merge(vector<int>& nums, int begin, int mid, int end) {
        --begin;
        int l{0};
        int le{mid - begin};
        int r{le};
        int re{end - begin};
        vector<int> temp{nums.begin() + begin, nums.begin() + end};
        for(int i{begin}; i < end; ++i)
            if(l < le && r < re)
                nums[i] = temp[l] <= temp[r] ? temp[l++] : temp[r++];
            else
                nums[i] = l < le ? temp[l++] : temp[r++];
    }

    void merge_sort(vector<int>& nums, int begin, int end) { 
        if(begin >= end) return;
        int mid{begin + (end - begin)/2};
        merge_sort(nums, begin, mid);
        merge_sort(nums, mid + 1, end);
        merge(nums, begin, mid, end);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums, 1, nums.size());
        return nums;
    }
};

