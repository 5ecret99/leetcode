class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        /*
        int nlen=nums.size();
        
        for(int i=0;i<nlen;i++)
            {
            int limit=i+k+1;
            limit= limit<nlen ? limit:nlen;
            
            for(int a=i+1;a<limit;a++)
                if(nums[i]==nums[a])
                    return true;
            }
        return false;Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.


        */
         unordered_set<int> set;
        for(int i=0;i<nums.size();i++)
            {
            if(set.count(nums[i])) return true;
            set.insert(nums[i]);
            if(set.size()>k)
                set.erase(nums[i-k]);
            }
        return false;

    }
};