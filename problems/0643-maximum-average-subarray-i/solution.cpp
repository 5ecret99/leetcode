class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int nsum=0;

        
        for(int i=0;i<k;i++){nsum+=nums[i];}
        
        int curr_sum=nsum;
        
        for(int i=1;i+k-1<nums.size();i++)
            {
            curr_sum=curr_sum-nums[i-1]+nums[i+k-1];
            if(curr_sum>nsum){nsum=curr_sum;}
            }
        
     return nsum/double(k);   
    }
};
