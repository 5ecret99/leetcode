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
    bool isValidBST(TreeNode* root, double min = -2147483649, double max = 2147483648) {    
        if(!root) return true;

        return min < root->val && root->val < max
        && isValidBST(root->left, min, root->val)
        && isValidBST(root->right, root->val, max);  
    }
};