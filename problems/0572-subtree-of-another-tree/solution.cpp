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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p || !q) return p == q ? true:false;

        return p->val == q->val 
        && isSameTree(p->right, q->right)
        && isSameTree(p->left, q->left);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return isSameTree(root, subRoot)
        || (root && (isSubtree(root->right, subRoot) 
        || isSubtree(root->left, subRoot)));
    }
};
