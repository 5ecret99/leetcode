/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> map{};

public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        if(map.find(node) != map.end()) return map[node];
        Node* cloned_node = new Node(node->val);
        map[node] = cloned_node;
        for(auto neighbor : node->neighbors)
            cloned_node->neighbors.push_back(cloneGraph(neighbor));

        return cloned_node; 
    }
};