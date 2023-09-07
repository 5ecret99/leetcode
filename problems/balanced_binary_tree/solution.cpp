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
    bool balanced{true};
    int height(TreeNode* node){
        if(!node || !balanced) return 0;
        auto left = height(node->left);
        auto right = height(node->right);

        if (abs(right - left) > 1) balanced = false; 
        return 1 + max(left, right);
    }
public:
    bool isBalanced(TreeNode* root) {
       height(root);
       return balanced; 
    }
};