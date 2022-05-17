class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int curr_sum=0,arr_count=0;
        for(int i=0;i<k;i++) curr_sum+=arr[i];
        
        if(curr_sum>= k*threshold) arr_count++;
        
        for(int i=k;i<arr.size();i++)
            {
            curr_sum=curr_sum-arr[i-k]+arr[i];
            if(curr_sum>= k*threshold) arr_count++;
            }
        return arr_count;
    }
};