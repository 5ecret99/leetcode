class Solution {
private:
    unordered_map<int, vector<int>> mp;
    unordered_set<int> visited;
    bool dfs(int node, int parent = -1){
        if(visited.contains(node)) return true;
        visited.insert(node);
        for(auto curr_node : mp[node])
            if(curr_node != parent && dfs(curr_node, node))
                return true;

        return false;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(const auto& edge: edges){
            mp[edge[0]].push_back(edge[1]);
            mp[edge[1]].push_back(edge[0]);
            if(dfs(edge[0])) return edge;
            visited.clear();
        }
        
        return {};
    }
};