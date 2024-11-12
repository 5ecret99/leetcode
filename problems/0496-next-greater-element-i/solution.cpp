class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int, int> elements;
        for(int i = 0; i < nums1.size(); ++i)
            elements[nums1[i]] = i;
        
        nums1 = vector<int>(nums1.size(), -1);

        int n = nums2.size();
        for(int i = n - 2; i >= 0; --i)
        {
            auto it = elements.find(nums2[i]);
            if(it != elements.end())
            {
                auto [num, pos] = *it;
                elements.erase(it);
                for(int j = i + 1; j < n; ++j)
                    if(nums2[j] > num)
                    {
                        nums1[pos] = nums2[j];
                        break;
                    }
                
                if(elements.empty())
                    break;
            }
        }

        
        return nums1;
    }
};
