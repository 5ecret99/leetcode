class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) 
    {
        int sec = 0;
        for(int i = 0; i < tickets.size(); ++i)
            sec+= min(tickets[i], tickets[k] - (i > k));
                       
        return sec;
    }
};
