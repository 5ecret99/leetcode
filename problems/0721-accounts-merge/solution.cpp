class Solution {
    class UnionFind
    {
        private:
        vector<int> parent_;
        int n_;
        public:
            void init(int n)
            {
                n_ = n;
                parent_.resize(n_);
                for(int i = 0; i < n_; ++i)
                    parent_[i] = i;
            }

            int find(int node)
            {
                if(parent_[node] != node)
                    parent_[node] = find(parent_[node]);
                
                return parent_[node];
            }

            void join(int node_a, int node_b)
            {
                int parent_a = find(node_a); 
                int parent_b = find(node_b); 
                if(parent_a != parent_b)
                    parent_[parent_b] = parent_a;
            }
    };

    UnionFind union_find;
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
    {
        int n = accounts.size();
        union_find.init(n);
        map<string, int> mp;
        for(int i = 0; i < n; ++i)
            for(int j = 1; j < accounts[i].size(); ++j)
            {
                auto it = mp.find(accounts[i][j]);
                if(it == mp.end())
                {
                    mp[accounts[i][j]] = i;
                }
                else
                {
                    union_find.join(it->second, i);
                }
            }
        
        int len = 0;
        for(int i = 0; i < n; ++i)
        {
            if(union_find.find(i) == i)
                ++len;
        }

        int new_ind = 0;
        unordered_map<int, int> new_indexes;
        vector<vector<string>> res(len);
        for(auto& [str, old_ind] : mp)
        {
            int parent = union_find.find(old_ind);
            auto it = new_indexes.find(parent);
            if(it == new_indexes.end())
            {
                new_indexes[parent] = new_ind;
                res[new_ind].push_back(accounts[parent][0]);
                res[new_ind].push_back(str);
                ++new_ind;
            }
            else
            {
                res[it->second].push_back(str);
            }

        }
        
        return res;
    }
};
