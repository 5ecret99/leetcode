class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0;
        int high = numbers.size() - 1;
        while(low < high){
            auto curr = numbers[low] + numbers[high];
            if(curr < target) low++;
            else if(curr > target) high--;
            else return {low + 1, high + 1};
        }
        
        return {};
    }
};