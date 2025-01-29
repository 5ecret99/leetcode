class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int low = INT_MIN; 
        int high = 0; 
        for(auto w : weights)
        {
            low = max(low, w);
            high+= w;
        }

        while(low < high)
        {
            int mid = low + (high - low) / 2;
            int dd = 1;
            int curr = mid;
            for(auto w : weights)
                if(curr - w >= 0)
                    curr-= w;
                else
                {
                    ++dd;
                    curr = mid - w;
                }
            
            if(dd <= days)
                high = mid;
            else
                low = mid + 1;
        }

       return low; 
    }
};
