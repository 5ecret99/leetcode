class Solution {
public:
    /*
    int max_prof(vector<int>& prices,int start,int end)
            {
            if(start>=end){return 0;}
            int prof=0;
            for(int i=start;i<end;i++)
                {
                for(int j=i+1;j<=end;j++)
                    {
                    int curr_prof=prices[j]-prices[i]+max_prof(prices,start,i-1)+max_prof(prices,j+1,end);
                    prof=max(prof,curr_prof);
                    }
                }
            return prof;
            }*/
    int maxProfit(vector<int>& prices) 
        {
        int prof=0;
        for(int i=1;i<prices.size();i++)
            {
            if (prices[i] > prices[i - 1])
                prof += prices[i] - prices[i - 1];
            }
        return prof;
        //return max_prof(prices,0,prices.size()-1);
        }
};
