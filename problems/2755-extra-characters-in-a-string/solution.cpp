#include <memory> 
class Solution 
{
private:
    struct Node
    {
        vector<shared_ptr<Node>> child;
        bool word_end = false;
        Node()
        {
            child.resize(26, nullptr);
        }
    };

    shared_ptr<Node> head;
    void add(const string& word)
    {
        if(!head)
            head = make_shared<Node>();
        
        auto curr = head;
        for(auto ch : word)
        {
            if(!curr->child[ch - 'a'])
                curr->child[ch - 'a'] = make_shared<Node>();

            curr = curr->child[ch - 'a'];
        }

        curr->word_end = true;
    }

public:
    int minExtraChar(string& s, vector<string>& dictionary) 
    {
        for(auto& word : dictionary)
            add(word);
        
        int n = s.size();
        vector<int> dp(n + 1);
        dp[n] = 0;
        for(int start = n - 1; start >= 0; --start)
        {
            dp[start] = dp[start + 1] + 1;
            auto curr = head;
            if(!curr) continue;
            for(int end = start; end < n; ++end)
            {
                if(!curr->child[s[end] - 'a']) break;
                curr = curr->child[s[end] - 'a'];
                if(curr->word_end)
                    dp[start] = min(dp[start], dp[end + 1]);
            }
        }
        
        return dp[0];
    }
};
