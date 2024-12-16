class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        priority_queue<pair<int, int>> pairs;
        for(int i = 0; i < nums1.size(); ++i)
            pairs.emplace(nums2[i], nums1[i]);
        
        long long sum = 0;
        long long res = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        while(!pairs.empty() && --k)
        {
            sum+= pairs.top().second;
            pq.push(pairs.top().second);
            pairs.pop();
        }

        while(!pairs.empty())
        {
            sum+= pairs.top().second;
            pq.push(pairs.top().second);
            res = max(res, sum * pairs.top().first);
            sum-= pq.top();
            pq.pop();
            pairs.pop();
        }
        
        return res;
    }
};
