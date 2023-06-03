class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        auto it = nums.rbegin() + 1;
        for(; it != nums.rend(); it++)
            if(*it < *(it - 1)) break;

        if(it == nums.rend()){
            reverse(nums.begin(), nums.end());
        }
        else{
            auto it_b = nums.rbegin();
            for(; it_b != it; it_b++)
                if(*it_b > *it) break;
                
            iter_swap(it, it_b);
            reverse(it.base(), nums.end());
        }
        
    }
};