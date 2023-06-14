/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private: 
    vector<vector<int>> res{};

public: 
    void helper(int level, TreeNode* node){
        if(!node) return;
        if(level >= res.size()) res.push_back({});

        res[level].push_back(node->val);
        helper(level + 1, node->left);
        helper(level + 1, node->right);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        helper(0, root);
        return res;
    }
};