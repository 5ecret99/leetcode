class Solution {
public:
    int totalMoney(int n) 
    {
        int complete_weeks = n / 7;
        int days_left = n % 7;
        return 7 * complete_weeks * (complete_weeks - 1) / 2
                + complete_weeks * 28
                + days_left * (days_left + 1) / 2 + complete_weeks * days_left;
    }
};
