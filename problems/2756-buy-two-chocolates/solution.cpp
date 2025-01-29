class Solution 
{
public:
    int buyChoco(vector<int>& prices, int money) 
    {
        vector<int> smallest(2, INT_MAX);
        for(auto p : prices)
            if(p < smallest[0])
            {
                smallest[1] = smallest[0];
                smallest[0] = p;
            }
            else if(p < smallest[1])
                smallest[1] = p;

        int res = money - smallest[0] - smallest[1]; 
        return res >= 0 ? res : money;
    }
};
