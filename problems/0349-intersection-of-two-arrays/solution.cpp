class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_set<int> st1{nums1.begin(), nums1.end()};
        vector<int> res; 
        for(auto n : nums2)
            if(st1.erase(n))
                res.push_back(n);
        
        return res;
    }
};
