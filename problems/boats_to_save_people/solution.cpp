class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        auto left{people.begin()};
        auto right{people.end() - 1};
        int boats{0};
        while(left <= right)
        {
            if(*left + *right <= limit) 
                ++left;
            
            --right;
            ++boats;
        }
        
        return boats;
    }
};
