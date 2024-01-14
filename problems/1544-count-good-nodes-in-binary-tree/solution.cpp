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
    int helper(TreeNode* node, int max_value = INT_MIN)
    {
        if(!node) return 0;
        max_value = max(max_value, node->val);

        return (node->val == max_value ? 1 : 0)
            + helper(node->left, max_value)
            + helper(node->right, max_value);
    }

public:
    int goodNodes(TreeNode* root) {
       return helper(root); 
    }
};
