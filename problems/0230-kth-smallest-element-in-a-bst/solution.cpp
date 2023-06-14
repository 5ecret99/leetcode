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
public:
    vector<int> values{};
    void helper(TreeNode* node){
        if(!node) return;
        helper(node->right);
        values.push_back(node->val);
        helper(node->left);
    }
    int kthSmallest(TreeNode* root, int k) {
        helper(root);
        return *(values.end() - k);
    }
};
