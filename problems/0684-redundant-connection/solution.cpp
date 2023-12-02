class Solution {
private:
    vector<int> parents{[]{
        int max_edges{10001};
        vector<int> vec(max_edges);
        for(int i = 1; i < max_edges; ++i) vec[i] = i;
        return vec;
    }()};

    int find_parent(int node){
        return parents[node] == node ? parents[node] : find_parent(parents[node]);
    }

    bool node_union(int node1, int node2){
        node1 = find_parent(node1);
        node2 = find_parent(node2);
        if(node1 == node2) return false;
        parents[node2] = node1;
        return true;
    }
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(const auto& nodes : edges)
            if(!node_union(nodes[0], nodes[1])) return nodes;
        
        return {};
    }
};
