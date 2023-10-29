class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> baskets;
        int left = 0;
        int right = 0;
        int max_fruit = 0;
        while(right < fruits.size())
        {
            baskets[fruits[right]]++;
            if(baskets.size() <= 2)
            {
                max_fruit = max(max_fruit, right - left + 1);
            }
            else
            {
                baskets[fruits[left]]--;
                if(!baskets[fruits[left]]) baskets.erase(fruits[left]);

                ++left;
            }
            
            ++right;
        }
        
        return max_fruit;
    }
};