class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> res;

        for(auto it_a = nums.begin(); it_a != nums.end(); it_a++){
            for(auto it_b = it_a + 1; it_b != nums.end(); it_b++){
                auto it_c = it_b + 1;
                auto it_d = nums.end() - 1;
                while(it_c < it_d){
                    long long int sum = *it_a;
                    sum+= *it_b;
                    sum+= *it_c;
                    sum+=*it_d;

                    if(sum == target){
                        s.insert({*it_a,*it_b,*it_c,*it_d});
                        it_c++;
                        it_d--;
                    }
                    else if (sum < target){
                        it_c++;
                    }
                    else {
                        it_d--;
                    }
                }
            }
        }

        for(auto quadruplets : s){
            res.push_back(quadruplets);
        }

        return res;
    }
};