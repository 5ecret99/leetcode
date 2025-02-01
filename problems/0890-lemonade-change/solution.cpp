class Solution {
public:
    bool lemonadeChange(vector<int>& bills) 
    {
        int five = 0;
        int ten = 0;
        for(auto b : bills)
        {
            if(b == 5)
                ++five;
            else if(b == 10)
                ++ten;

            int owned  = b - 5;
            if(owned > 0)
            {
                if(owned >= 10 && ten > 0)
                {
                    owned-= 10;
                    --ten;
                }

                if(owned > five * 5)
                    return false;
                else
                    five-= owned / 5;
            }
        }

        return true;
    }
};
