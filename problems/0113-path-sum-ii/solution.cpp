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
class Solution 
{
private:
    vector<vector<int>> res_;
    void pathSum(TreeNode* node, vector<int>& path, int target)
    {
        if(!node) return;
        path.push_back(node->val);
        if(!(node->left) && !(node->right) && node->val == target) res_.push_back(path);

        pathSum(node->left, path, target - node->val);
        pathSum(node->right, path, target - node->val);

        path.pop_back();
    } 

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<int> path;
        pathSum(root, path, targetSum);
        return res_; 
    }
};
