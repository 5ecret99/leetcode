class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_set<int> set1{nums1.begin(), nums1.end()};
        unordered_set<int> set2{nums2.begin(), nums2.end()};
        
        for(auto num : nums1)
            if(set2.contains(num))
            {
                set1.erase(num);
                set2.erase(num);
            }
        
        return {{set1.begin(), set1.end()}, {set2.begin(), set2.end()}};
    }
};
