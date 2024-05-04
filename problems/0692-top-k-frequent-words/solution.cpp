class Solution {
private:
struct comparator
{
    bool operator()(const pair<string_view, int>& a, const pair<string_view, int>& b)
    {
        return a.second == b.second 
            ? a.first > b.first
            : a.second < b.second;
    }
};
public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        unordered_map<string_view, int> word_freq;
        for(auto& word: words)
            word_freq[word]++;

        priority_queue<pair<string_view, int>, vector<pair<string_view, int>>, comparator> pq;
        for(auto [word, freq] : word_freq)
            pq.emplace(word, freq);
        
        int ind = 0;
        vector<string> res(k);
        while(ind < k)
        {
            res[ind++] = pq.top().first;
            pq.pop();
        }

        return res;
    }
};
