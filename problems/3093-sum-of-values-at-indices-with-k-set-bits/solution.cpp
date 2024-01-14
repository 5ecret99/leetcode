class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum{0};
        for(int ind = 0; ind < nums.size(); ++ind){
            int i{ind};
            int bit_num{0};
            while(i){
                if(i & 1) ++bit_num;
                i>>= 1;
            }

            if (bit_num == k) sum+=nums[ind]; 
        }
        
        return sum;
    }
};
